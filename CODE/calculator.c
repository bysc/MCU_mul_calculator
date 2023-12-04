#include "system.h"
#include <stdio.h>
typedef unsigned char u8;
typedef unsigned int u16;
bit end_mark=0;//calculatorר��
void main()
{
	unsigned char press;//����ֵ��ȡ
	unsigned char str[17];
  char index=-1;
	bit mode=0;//0Ϊcalculator��1Ϊ2ת16����
	bit turn=0;//0��ʾlcd�ػ���1��ʾ����
/*===================����ͨ��===========================*/	
	clearStr(str,17);
	while(1)	
	{
		press=key_getvalue();
		if(press==255) continue;//�ް�������	
		//������ȼ������ػ�
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
		//�ػ����
		if(turn==0) continue;
		//����ɨ�裬ģʽѡ��,ģʽ���ȼ���end_mark��
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
