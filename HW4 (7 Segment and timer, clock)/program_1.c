/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
� Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 5/16/2020
Author  : PerTic@n
Company : If You Like This Software,Buy It
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*****************************************************/

#include <mega32.h>
#include <delay.h>

// Declare your global variables here

void main(void)
{
// Declare your local variables here
unsigned char a = 5;
// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x00;

// Port C initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTC=0x00;
DDRC=0xFF;

// Port D initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTD=0x00;
DDRD=0xFF;


while (1)
      {
      // Place your code here
      //Digit 1
      PORTD = 0b11111110;
      PORTC = 0x6F;
      delay_ms(a);
      // Digit 2
      PORTD = 0b11111101;
      PORTC = 0x7F;
      delay_ms(a);
      // Digit 3
      PORTD = 0b11111011;
      PORTC = 0x3F;
      delay_ms(a);
      // Digit 4
      PORTD = 0b11110111;
      PORTC = 0x5B;
      delay_ms(a);
      // Digit 5
      PORTD = 0b11101111;
      PORTC = 0x4F;
      delay_ms(a);
      // Digit 6
      PORTD = 0b11011111;
      PORTC = 0x3F;
      delay_ms(a);
      }
}