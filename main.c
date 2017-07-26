#include "LCD.h"


int main()
{
	lcd_init();
	while(1){
		lcd_gotoxy(1,1);
		lcd_print("yeah bitch !");
	}
	
}