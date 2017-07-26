#include "LCD.h"


void __high_to_low_pulse(void){
	LCD_PRT |= (1<<LCD_EN);	
	_delay_us(1);
	LCD_PRT &= ~(1<<LCD_EN);
	_delay_us(2);
}

void __lcd_command(unsigned char cmnd){
	LCD_PRT = (cmnd & 0xF0) | (LCD_PRT & 0x0F) ;
	LCD_PRT &= ~(1<<LCD_RS) ;
	__high_to_low_pulse();
	_delay_us(20);
	LCD_PRT = (cmnd <<4) | (LCD_PRT & 0x0F) ;
	__high_to_low_pulse() ;
}

void __lcd_write_data(unsigned char data){
	LCD_PRT = (data & 0xF0) | (LCD_PRT & 0x0F) ;	
	LCD_PRT |= (1<<LCD_RS) ;
	__high_to_low_pulse();
	LCD_PRT = (data <<4 ) | (LCD_PRT & 0x0F) ;	
	__high_to_low_pulse();
}
	
void lcd_init(){

	LCD_DDR = 0xFF ;
	LCD_PRT &= ~(1<<LCD_EN) ;
	_delay_us(1000);
	__lcd_command(0x33);
	_delay_us(100);
	__lcd_command(0x32);
	_delay_us(100);
	__lcd_command(0x28);
	_delay_us(100);
	__lcd_command(0x0E);
	_delay_us(100);
	__lcd_command(0x01);
	_delay_us(2000);
	__lcd_command(0x06);
	_delay_us(100);
}


void lcd_gotoxy(unsigned char x, unsigned char y){
	unsigned char firsAdr[] = {0x80, 0xC0, 0x94, 0xD4} ;
	__lcd_command(firsAdr[y-1] + x - 1);
	_delay_us(100);
}


void lcd_print(char* str){

	unsigned char i = 0 ;
	while(str[i] != 0){
		__lcd_write_data(str[i]);
		i++ ;
	}

}

void lcd_clear_display(){
	__lcd_command(0x01) ;
	_delay_ms(2);
}
