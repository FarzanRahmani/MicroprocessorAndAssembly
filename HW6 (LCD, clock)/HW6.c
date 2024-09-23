/* HW6
    Farzan Rahmani
    99521271
*/

#include <mega32.h>
#include <stdlib.h>
#include <string.h>
#include <delay.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here
unsigned int milisecond = 0;
char str_ms[]; 
unsigned int second = 0;
char str_s[];
unsigned int minute = 58;
char str_m[];
unsigned int hour = 23;
char str_h[];

interrupt[TIM1_COMPA] void timer1_compa_isr(void) // occurs every 0.1s
{
    milisecond += 1;

    if (milisecond == 10)
    {
        milisecond = 0;
        second++;
    }

    if (second == 60)
    {
        lcd_gotoxy(9, 1); // (9, 1):Tens of second, (10, 1):Units of second
        lcd_puts("  ");
        second = 0;
        minute++;
    }

    if (minute == 60)
    {
        lcd_gotoxy(6, 1); // (6, 1):Tens of minute, (7, 1):Units of minute
        lcd_puts("  ");
        minute = 0;
        hour++;
    }

    if (hour == 24)
    {
        lcd_gotoxy(3, 1); // (3, 1):Tens of hour, (4, 1):Units of hour
        lcd_puts("  ");
        hour = 0;
    }

    itoa(milisecond, str_ms); // convert int to string
    lcd_gotoxy(12, 1); // (12, 1):Tens of milisecond, (13, 1):Units of milisecond
    lcd_puts(str_ms);

    itoa(second, str_s); // convert int to string
    lcd_gotoxy(9, 1); // (9, 1):Tens of second, (10, 1):Units of second
    lcd_puts(str_s);

    itoa(minute, str_m); // convert int to string
    lcd_gotoxy(6, 1); // (6, 1):Tens of minute, (7, 1):Units of minute
    lcd_puts(str_m);

    itoa(hour, str_h); // convert int to string
    lcd_gotoxy(3, 1); // (3, 1):Tens of hour, (4, 1):Units of hour
    lcd_puts(str_h);
}

void main(void)
{
    // Declare your local variables here
    // port initialization: port C as output
    DDRC = 0xFF;
    PORTC = 0x00;
    // Timer/Counter 1 initialization (16-bit timer) 
    TCCR1A = 0x00;
    TCCR1B = 0x0C;
    TCNT1H = 0x00;
    TCNT1L = 0x00;
    ICR1H = 0x00;
    ICR1L = 0x00;
    OCR1AH = 0x0C;
    OCR1AL = 0x35;
    OCR1BH = 0x00;
    OCR1BL = 0x00;
    TIMSK = 0x10;

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

// Global enable interrupts
#asm("sei")
    lcd_init(16); // Characters/line: 16
    lcd_clear();

    lcd_gotoxy(3, 0);
    lcd_puts("LCD CLOCK");

    // (3, 1):Tens of hour, (4, 1):Units of hour
    lcd_gotoxy(5, 1);
    lcd_puts(":");
    // (6, 1):Tens of minute, (7, 1):Units of minute
    lcd_gotoxy(8, 1);
    lcd_puts(":");
    // (9, 1):Tens of second, (10, 1):Units of second
    lcd_gotoxy(11, 1);
    lcd_puts(":");

    while (1)
    {
        // Place your code here
    }
}
