#ifndef F_CPU
#define F_CPU 1000000UL  // will be external 16 MHz in the future
#endif

#include <avr/io.h>
#include <util/delay.h>

#define LCD_PRT  PORTA
#define LCD_DDR  DDRA
#define LCD_PIN  PINA
#define LCD_RS   0	// register select
#define LCD_RW   1	// read/write pin
#define LCD_EN   2	// enable pin 


	
void lcd_init();  // initialize LCD

void lcd_gotoxy(unsigned char x, unsigned char y);

void lcd_print(char* str);	// print strings

void lcd_clear_display();	

