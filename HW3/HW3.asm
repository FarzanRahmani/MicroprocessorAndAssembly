; HW3
; Farzan Rahmani
; 99521271

.include "m32def.inc"

.ORG	0 ; reset vector
	RJMP		MAIN ; jump to main program
.ORG	OC1Aaddr ; output compare 1A interrupt vector
	RJMP		OC1Aaddr_ROUTINE ; jump to OC1Aaddr_ROUTINE

MAIN: ; main program
	LDI		R16,HIGH(RAMEND) ; Initialize Stack Pointer
	OUT		SPH,R16
	LDI		R16,LOW(RAMEND)
	OUT		SPL,R16

	LDI		R16,0xFF
	OUT		DDRC,R16; PORTC as output
	OUT		DDRD,R16; PORTD as output

	;Enable Pullup Resistor on PORTA 
	OUT		PORTA,R16
	
	LDI		R16,0x00
	OUT		DDRA,R16;PORTA as input

	;initialing PORTB
	LDI		R16, 0xFF
	OUT		DDRB, R16; PORTB as output


BEGIN: ; checking the button
    IN		R16,PINA
	CPI 	R16,0b1
	BREQ    BEGIN1
	LDI		R20,0           ; yekan (LSB) = 0
	LDI		R21,0			; dahgan = 0
	LDI		R22,0			; sadgan = 0
	LDI     R23,0			; hezargan (MSB) = 0
	LDI     R24,0
	LDI		R26,1			
	LDI		R27,0x0A
	LDI		R28,0
		
	RJMP		SET_TIMER

BEGIN1: ; setting the initial value of the counter
	LDI		R20,9			; yekan (LSB) = 9
	LDI		R21,9			; dahgan = 9
	LDI		R22,9			; sadgan = 9
	LDI     R23,9			; hezargan (MSB) = 9
	
	LDI		R26,-1
	LDI		R27,-1
	LDI		R28,9
	
	RJMP	SET_TIMER

SET_TIMER: ; setting the timer
	LDI		R25, 0X00
	OUT		TCCR1A, R25
	
	LDI		R25, 0X0C
	OUT		TCCR1B, R25

	LDI		R25, HIGH(31250)
	OUT		OCR1AH, R25
	
	LDI		R25, LOW(31250)
	OUT		OCR1AL, R25
		
	LDI		R25, 0X12
	OUT		TIMSK, R25
		
	SEI

Y1: ; displaying the number
    LDI		R16,0b1110	;displaying hezaregan
	OUT		PORTD,R16
	MOV		R16,R23
	CALL		CNVRT
	OUT		PORTC,R16
	CALL		DELAY

	LDI		R16,0b1101	
	OUT		PORTD,R16
	MOV		R16,R22
	CALL	CNVRT
	OUT		PORTC,R16
	CALL	DELAY
		
	LDI		R16,0b1011	
	OUT		PORTD,R16
	MOV		R16,R21
	CALL	CNVRT
	OUT		PORTC,R16
	CALL	DELAY

	LDI		R16,0b0111	;displaying yekan 
	OUT		PORTD,R16
	MOV		R16,R20
	CALL	CNVRT
	OUT		PORTC,R16
	CALL	DELAY
		
	IN		R16,PINA	;Check
	CPI 	R16,0b1
	BREQ 	SET_VALUE
		
	LDI		R26,1			
	LDI		R27,0x0A
	LDI		R28,0
		
	RJMP	Y1

SET_VALUE: ; setting the value of the counter
	LDI		R26,-1
	LDI		R27,-1
	LDI		R28,9
	RJMP	Y1

OC1Aaddr_ROUTINE:	 ; output compare 1A interrupt routine
	Add  		R20, R26
	CP   		R20, R27
	BRNE 		Y2
		
	MOV  		R20, R28
	Add  		R21, R26
	CP   		R21, R27
	BRNE 		Y2
		
	MOV 		R21, R28
	Add  		R22, R26
	CP   		R22 ,R27
	BRNE 		Y2
	
	MOV  		R22, R28
	Add  		R23, R26
	CP   		R23, R27
	BRNE		Y2
		
	MOV  		R23, R28

Y2:  
	RETI

DELAY:LDI	R17,0x01 ; delay 1 second
L1:	LDI		R18,0xFF
L2:	LDI		R19,0xAA
L3:	DEC		R19
	BRNE	L3
	DEC		R18
	BRNE	L2
	DEC		R17
	BRNE	L1
	RET				


;converts a digit to 7 segment code 
CNVRT:	
	CPI		R16,0
	BRNE	C1
	LDI		R16,0x3F
	RET

C1:	CPI		R16,1
	BRNE	C2
	LDI		R16,0x06
	RET

C2:	CPI		R16,2
	BRNE	C3
	LDI		R16,0x5B
	RET

C3:	CPI		R16,3
	BRNE	C4
	LDI		R16,0x4F
	RET

C4:	CPI		R16,4
	BRNE	C5
	LDI		R16,0x66
	RET

C5:	CPI		R16,5
	BRNE	C6
	LDI		R16,0x6D
	RET

C6:	CPI		R16,6
	BRNE	C7
	LDI		R16,0x7D
	RET

C7:	CPI		R16,7
	BRNE	C8
	LDI		R16,0x07
	RET

C8:	CPI		R16,8
	BRNE	C9
	LDI		R16,0x7F
	RET

C9:	CPI		R16,9
	BRNE	C10
	LDI		R16,0x6F

C10:	RET