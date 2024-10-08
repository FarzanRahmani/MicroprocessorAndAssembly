.include "m32def.inc"
		LDI		R16,HIGH(RAMEND)
		OUT		SPH,R16
		LDI		R16,LOW(RAMEND)
		OUT		SPL,R16

		LDI		R16,0xFF
		OUT		DDRC,R16		;PORTC as output
		OUT		DDRD,R16		;PORTD as output
		OUT		PORTA,R16		;Enabling Pullup Resistor on PORTA 
		LDI		R16,0x00
		OUT		DDRA,R16		;PORTA as input

BEGIN:	IN		R16,PINA
		;LDI		R16,64
		MOV		R17,R16
		LDI		R20,0
		LDI		R21,0
		LDI		R22,0

D0:		CPI		R17,100
		BRLO 	D1
		LDI		R18,100
		SUB		R17,R18
		LDI		R19,01
		ADD		R20,R19			;Sadgan
		RJMP	D0

D1:		CPI		R17,10
		BRLO	D2
		LDI		R18,10
		SUB		R17,R18
		LDI		R19,01
		ADD		R21,R19			;Dahgan
		RJMP	D1
D2:		MOV		R22,R17			;Yekan

		LDI		R16,0b11111110	;displaying Yekan
		OUT		PORTD,R16
		MOV		R16,R20
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY

		LDI		R16,0b11111101	;displaying Dahgan
		OUT		PORTD,R16
		MOV		R16,R21
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY

		LDI		R16,0b11111011	;displaying Sadgan
		OUT		PORTD,R16
		MOV		R16,R22
		CALL	CONVERT
		OUT		PORTC,R16
		CALL	DELAY
		RJMP	BEGIN

DELAY:	LDI		R17,0x01
L1:		LDI		R18,0xFF
L2:		LDI		R19,0xFF
L3:		DEC		R19
		BRNE	L3
		DEC		R18
		BRNE	L2
		DEC		R17
		BRNE	L1
		RET

CONVERT:				;converts a digit to 7seg code 
		CPI		R16,0
		BRNE	C1
		LDI		R16,0x3F
		RET
C1:		CPI		R16,1
		BRNE	C2
		LDI		R16,0x06
		RET
C2:		CPI		R16,2
		BRNE	C3
		LDI		R16,0x5B
		RET
C3:		CPI		R16,3
		BRNE	C4
		LDI		R16,0x4F
		RET
C4:		CPI		R16,4
		BRNE	C5
		LDI		R16,0x66
		RET
C5:		CPI		R16,5
		BRNE	C6
		LDI		R16,0x6D
		RET
C6:		CPI		R16,6
		BRNE	C7
		LDI		R16,0x7D
		RET
C7:		CPI		R16,7
		BRNE	C8
		LDI		R16,0x07
		RET
C8:		CPI		R16,8
		BRNE	C9
		LDI		R16,0x7F
		RET
C9:		CPI		R16,9
		BRNE	C10
		LDI		R16,0x6F
C10:	RET
					