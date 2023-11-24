#include "lcd1602.h"
void lcd_delay(unsigned int times)
{
	unsigned int i,j;
	for(i=0;i<times;i++)
		for(j=0;j<112;j++);
}
void lcd_writecmd(unsigned char cmd)
{
	RS=0;
	RW=0;
	EN=0;
	LCD=cmd;
	lcd_delay(2);
	EN=1;
	lcd_delay(2);
	EN=0;
}
void lcd_writedata(unsigned char mydata)
{
	RS=1;
	RW=0;
	EN=0;
	LCD=mydata;
	lcd_delay(2);
	EN=1;
	lcd_delay(2);
	EN=0;
}
void lcd_printstr(unsigned char*str)
{
	while(*str!='\0')
		lcd_writedata(*str++);
}
void lcd_turnon()
{
	lcd_writecmd(0x0c);
}
void lcd_turnoff()
{
	lcd_writecmd(0x08);
}
void lcd_gotoxy(unsigned char x,unsigned char y)
{
	if(x==0) lcd_writecmd(0x80+y);
	if(x==1) lcd_writecmd(0xc0+y);
}
void lcd_init()
{
	lcd_writecmd(0x38);//8位，16*2,5*7
	lcd_writecmd(0x0c);//开启，无光标，不闪烁
	lcd_writecmd(0x06);//光标右移，不整体移动
	lcd_writecmd(0x01);//清屏
}