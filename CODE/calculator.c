#include "system.h"
#include <stdio.h>
typedef unsigned char u8;
typedef unsigned int u16;
bit end_mark=0;//calculator专用
void main()
{
	unsigned char press;//按键值读取
	unsigned char str[17];
  char index=-1;
	bit mode=0;//0为calculator，1为2转16进制
	bit turn=0;//0表示lcd关机，1表示开机
/*===================以上通用===========================*/	
	clearStr(str,17);
	while(1)	
	{
		press=key_getvalue();
		if(press==255) continue;//无按键按下	
		//最高优先级，开关机
		else if(press=='t')
		{
			turn=~turn;
			if(turn==0) 
			{
				lcd_writecmd(0x01);
				lcd_printstr("see you");
				lcd_delay(1000);
				lcd_turnoff();
				mode=0;
				end_mark=0;
				clearStr(str,17);
				index=-1;
			}
			else welcome();
			continue;			
		}
		//关机检测
		if(turn==0) continue;
		//键盘扫描，模式选择,模式优先级比end_mark高
		else if(press=='#') 
		{
			mode=0;
			lcd_init();
			lcd_printstr("calculator");
			lcd_delay(1000);
			lcd_writecmd(0x01);
			clearStr(str,17);
			index=-1;
			end_mark=0;
		}
		else if(press=='$') 
		{
			mode=1;
			lcd_init();
			lcd_printstr("bin_hex convert");
			lcd_delay(1000);
			lcd_writecmd(0x01);
			clearStr(str,17);
			index=-1;
		}
		else if(mode==0) calculator(str,&index,press);
		else binToHEX(str,&index,press);
	}
}
