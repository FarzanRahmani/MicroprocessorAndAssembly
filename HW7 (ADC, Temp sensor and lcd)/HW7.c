/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : HW7
Version :
Date    : 11/23/2023
Author  : Farzan Rahmani  99521271
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
#include <stdlib.h>
#include <stdio.h>
#include <delay.h>

// Alphanumeric LCD functions
#include <alcd.h>

#define ADC_VREF_TYPE 0x40

int temp = 0;
// char output[10];
char show_arr[5]; // for showing the temperature on LCD

unsigned int read_adc(unsigned char adc_input)
{
    ADMUX = adc_input | (ADC_VREF_TYPE & 0xff);

    // Delay needed for the stabilization of the ADC input voltage
    delay_us(10);

    ADCSRA |= 0x40;
    while ((ADCSRA & 0x10) == 0)
        ;
    ADCSRA |= 0x10;
    return ADCW;
}

void main(void)
{
    // Declare your local variables here

    // Input/Output Ports initialization
    // Port A initialization
    // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
    // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
    PORTA = 0x00;
    DDRA = 0x00;

    // Port B initialization
    PORTB = 0x00;
    DDRB = 0x00;

    // Port C initialization
    PORTC = 0xFF;
    DDRC = 0x00;

    // Port D initialization
    PORTD = 0x00;
    DDRD = 0x00;

    // Timer/Counter 0 initialization
    // Clock source: System Clock
    // Clock value: Timer 0 Stopped
    // Mode: Normal top=0xFF
    // OC0 output: Disconnected
    TCCR0 = 0x00;
    TCNT0 = 0x00;
    OCR0 = 0x00;

    // Timer/Counter 1 initialization
    // Clock source: System Clock
    // Clock value: Timer1 Stopped
    // Mode: Normal top=0xFFFF
    // OC1A output: Discon.
    // OC1B output: Discon.
    // Noise Canceler: Off
    // Input Capture on Falling Edge
    // Timer1 Overflow Interrupt: Off
    // Input Capture Interrupt: Off
    // Compare A Match Interrupt: Off
    // Compare B Match Interrupt: Off
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

    // Timer/Counter 2 initialization
    ASSR = 0x00;
    TCCR2 = 0x00;
    TCNT2 = 0x00;
    OCR2 = 0x00;

    // External Interrupt(s) initialization
    // INT0: Off
    // INT1: Off
    // INT2: Off
    MCUCR = 0x00;
    MCUCSR = 0x00;

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK = 0x00;

    // USART initialization
    // USART disabled
    UCSRB = 0x00;

    // Analog Comparator initialization
    // Analog Comparator: Off
    // Analog Comparator Input Capture by Timer/Counter 1: Off
    ACSR = 0x80;
    SFIOR = 0x00;

    // ADC initialization
    // ADC Clock frequency: 250.000 kHz
    // ADC Voltage Reference: AVCC pin
    ADMUX = ADC_VREF_TYPE & 0xff;
    ADCSRA = 0x85;

    // SPI initialization
    // SPI disabled
    SPCR = 0x00;

    // TWI initialization
    // TWI disabled
    TWCR = 0x00;

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
    lcd_clear();
    lcd_gotoxy(3, 0);
    lcd_puts("LM35 Sensor");

    lcd_gotoxy(3, 1);
    lcd_puts("Temp:"); // 3 + 5 = 8
    // 8 + 5 = 13 (00.00)
    // 9 to 13 is for showing the temperature
    lcd_gotoxy(14, 1);
    lcd_putchar(223);  // 223 is for degree symbol
    lcd_gotoxy(15, 1);
    lcd_puts("C");

    while (1)
    {
        temp = read_adc(0);
        temp = (temp * 4.8898);
        temp = temp / 10;
        // temp = temp / 2;

        lcd_gotoxy(9, 1);

        ftoa(temp, 2, show_arr); // convert float to string
        lcd_puts(show_arr);
        // sprintf(output, "%d", temp);
        // lcd_puts(output);

        // lcd_gotoxy(14, 1);
        // lcd_putchar(223);  // 223 is for degree symbol
        // lcd_gotoxy(15, 1);
        // lcd_puts("C");


        delay_ms(1000);
    }
}
