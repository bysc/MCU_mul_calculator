#include "system.h"
void welcome()
{
	lcd_init();
	lcd_printstr("Welcome!");
	lcd_gotoxy(1,0);
	lcd_printstr("bysc");
	lcd_delay(500);
	lcd_writecmd(0x01);
}
