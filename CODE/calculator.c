#include "system.h"
#include <stdio.h>
typedef unsigned char u8;
typedef unsigned int u16;
void main()
{
	unsigned char press;//����ֵ��ȡ
	unsigned char str[17];
	unsigned char index=-1;
	bit end_mark=0;
	welcome();
	lcd_delay(500);
	clearStr(str,17);
	while(1)	
		
	{
		press=key_getvalue();
		if(press==255) continue;
		else if(end_mark)
		{
			lcd_init();
			end_mark=0;
		}
		else if(press=='=') 
		{
			getAnswer(str,&index);
			end_mark=1;//������������������㲢��ʼ��
		}
		else addStr(str,&index,press);
	}
}
