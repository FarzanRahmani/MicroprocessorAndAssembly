/*****************************************************
Date    : 6/16/2020
Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
*****************************************************/

#include <mega32.h>

// Alphanumeric LCD functions
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>

signed char a = 0;

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
// Place your code here
a++;
delay_ms(10);
}

// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void)
{
// Place your code here
a--;
delay_ms(10);
}

// Declare your global variables here

void main(void)
{
// Declare your local variables here
char *str;

// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Falling Edge
// INT1: On
// INT1 Mode: Falling Edge
// INT2: Off
GICR=0xC0;
MCUCR=0x0A;
MCUCSR=0x00;
GIFR=0xC0;

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 0
// RD - PORTC Bit 1
// EN - PORTC Bit 2
// D4 - PORTC Bit 4
// D5 - PORTC Bit 5
// D6 - PORTC Bit 6
// D7 - PORTC Bit 7
// Characters/line: 16
lcd_init(16);

// Global enable interrupts
#asm("sei")

while (1)
      {
      // Place your code here
      lcd_gotoxy(0,0);
      itoa(a,str);  // convert integer to string                                                                                    
      lcd_puts(str); // display string on LCD
      lcd_putchar(' '); // display space on LCD
      lcd_putchar(' ');
      delay_ms(50);
      }
}