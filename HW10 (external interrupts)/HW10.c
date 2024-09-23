/*******************************************************
Farzan Rahmani
99521271

This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : HW10
Version :
Date    : 12/12/2023
Author  : Farzan Rahmani
Company : IUST
Comments:


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>

// Alphanumeric LCD functions
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>
signed char a = 0;

interrupt[EXT_INT0] void ext_int0_isr(void)
{
  // Place your code here
  if (PORTC .3 == 0) // if 3rd bit of PORTC is 0 (LED is off)
  {
    a = a + 1;
  }
  else // if 3rd bit of PORTC is 1 (LED is on)
  {
    a = a + 10;
  }
}

interrupt[EXT_INT1] void ext_int1_isr(void)
{

  if (PORTC .3 == 0) // if 3rd bit of PORTC is 0 (LED is off)
  {
    a = a - 1;
  }
  else // if 3rd bit of PORTC is 1 (LED is on)
  {
    a = a - 10;
  }
}
interrupt[EXT_INT2] void ext_int2_isr(void)
{
  // Place your code here
  // (1 << 3) -> 0b00001000
  PORTC = PORTC ^ (1 << 3); // toggle 3rd bit of PORTC (PORTC.3) (^ is XOR)
  // PORTC.3 == 1 -> LED is on
  // PORTC.3 == 0 -> LED is off
}

void main(void)
{
  // Declare your local variables here
  char *str;

  PORTA = 0x00;
  DDRA = 0x00;

  PORTB = 0x00;
  DDRB = 0x00;

  PORTC = 0x00;
  DDRC = 0x08; // 0b00001000: 3rd bit is output for LED

  PORTD = 0x00;
  DDRD = 0x00;

  TCCR0 = 0x00;
  TCNT0 = 0x00;
  OCR0 = 0x00;

  TCCR1A = 0x00;
  TCCR1B = 0x00;
  TCNT1H = 0x00;
  TCNT1L = 0x00;
  ICR1H = 0x00;
  ICR1L = 0x00;
  OCR1AH = 0x00;
  OCR1AL = 0x00;
  OCR1BH = 0x00;
  OCR1BL = 0x00;

  ASSR = 0x00;
  TCCR2 = 0x00;
  TCNT2 = 0x00;
  OCR2 = 0x00;

  // External Interrupt(s) initialization
  GICR |= 0xE0; // 1110 0000
  MCUCR = 0x0A; // 0000 1010
  MCUCSR = 0x00;
  GIFR = 0xE0; // 1110 0000

  TIMSK = 0x00;

  UCSRB = 0x00;

  ACSR = 0x80;
  SFIOR = 0x00;

  ADCSRA = 0x00;

  SPCR = 0x00;

  TWCR = 0x00;

  lcd_init(16);

// Global enable interrupts
#asm("sei")

  while (1)
  {
    // Place your code here
    lcd_gotoxy(0, 0); // 0,0 (16*2)
    itoa(a, str); // convert int to string
    lcd_puts(str); // put string on lcd
    lcd_putchar(' '); // put space
    lcd_putchar(' ');
    delay_ms(50);
  }
}