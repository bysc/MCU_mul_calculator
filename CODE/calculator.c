#include "system.h"
#include <stdio.h>
#incude <string.h>
typedef unsigned char u8;
typedef unsigned int u16;
void main()
{
	unsigned char press;//°´¼üÖµ¶ÁÈ¡
	unsigned char str[16];
	float x1,x2,y;
	unsigned char i,j;
	bit point1;
	bit point2;
	unsigned char operation=0;
	welcome();
	lcd_delay(500);
	while(1)	
		
	{
		switch(press=key_getvalue())
		{
			case 255:break;
			case '.':
				lcd_init();
			  x1=0;
			  x2=0;
			operation=0;
			  break;
			case '=':
				lcd_writedata('=');
			  lcd_gotoxy(1,0);
				switch (operation)
				{
					case '+':y=x1+x2;break;
					case '-':y=x1-x2;break;
					case '*':y=x1*x2;break;
					case '/':y=x1/x2;break;
					default:y=x1;break;
				}
				sprintf(str,"%0.5f",y);
				lcd_printstr(str);
			break;
			case '+':operation='+';lcd_writedata('+');break;
			case '-':operation='-';lcd_writedata('-');break;
			case '*':operation='*';lcd_writedata('*');break;
			case '/':operation='/';lcd_writedata('/');break;
			default:
				lcd_writedata(press);
				if(!operation) x1=x1*10+press-'0';
			  else x2=x2*10+press-'0'; 
		}
	}
}
