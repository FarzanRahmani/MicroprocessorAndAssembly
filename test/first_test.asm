; Farzan Rahmani
; 99521271

.include "m32def.inc" ; include definition file for ATmega32
    ; initialize stack pointer (SP), so that stack can be used to store local variables and call functions
    LDI      R16,HIGH(RAMEND)
    OUT      SPH,R16 
    LDI      R16,LOW(RAMEND)
    OUT      SPL,R16 

    LDI      R16,0xFF ; 0b11111111
    OUT      DDRB,R16 ; set all pins of PORTB as output

L1: LDI      R16,0b00000001

START:
    OUT      PORTB,R16
    CALL     DELAY
    LSL      R16 ; logical shift left: 0b00000001 -> 0b00000010 -> 0b00000100 -> 0b00001000 -> 0b00010000 -> 0b00100000 -> 0b01000000 -> 0b10000000 -> 0b00000000 
    CPI      R16,0 ; compare R16 with 0 (compare immediate)
    BRNE     START

L2: LDI      R16,0b10000000 ; 0b00000000 -> 0b10000000

REVERSE:
    OUT      PORTB,R16
    CALL     DELAY
    LSR      R16 ; logical shift right: 0b10000000 -> 0b01000000 -> 0b00100000 -> 0b00010000 -> 0b00001000 -> 0b00000100 -> 0b00000010 -> 0b00000001 -> 0b00000000
    BRNE     REVERSE ; branch if not equal (Z flag is set to 1 if R16 is zero)
    JMP      L1 ; unconditional jump
    ;RJMP     L1 ; relative jump

DELAY:
    LDI      R17,0xFF ; 0b11111111
L3: IN       R18,PINA ; read from PINA
L4: LDI      R19,0x10 ; 0b00010000
L5: DEC      R19
    BRNE     L5 ; branch if not equal (Z flag is set to 1 if R19 is zero)
    DEC      R18
    BRNE     L4 ; branch if not equal (Z flag is set to 1 if R18 is zero)
    DEC      R17 
    BRNE     L3 ; branch if not equal (Z flag is set to 1 if R17 is zero)
    RET  
