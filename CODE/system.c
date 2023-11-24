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
void clearStr(unsigned char *str,unsigned char len)
{
	unsigned char i;
	for(i=0;i<len;i++) str[i]='\0';
}
void addStr(unsigned char *str,unsigned char *index,unsigned char press)
{
	if(*index==15) 
	{
		lcd_init();
		lcd_printstr("space overflower");
		lcd_delay(1000);
		lcd_init();
		lcd_printstr(str);
	}
	else
	{
		(*index)++;
		str[*index]=press;
		lcd_writedata(press);
	}
}
void delStr(unsigned char *str,unsigned char *index)
{
	if((*index)==-1)
	{
		lcd_init();
		lcd_printstr("space null");
		lcd_delay(1000);
	}
	else
	{
		str[*index]=0;
		(*index)--;
	}
	lcd_init();
	lcd_printstr(str);
}
void getAnswer(unsigned char *str,unsigned char *index)
{
	float x1=0,x2=0,y=0;
	bit point1=0,operation=0,point2=0;
	unsigned char action=0;
	unsigned char i;
	float power=1;//浮点加权
	
	if((*index)==-1)
	{
			lcd_printstr("nothing to print");
			lcd_delay(1000);
			lcd_init();
			return;			
	}
	for(i=0;i<=(*index);i++)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/') 
		{
			action=str[i];
			operation=1;
		}
		else if(str[i]=='.')//条件运算符不能做左值？
		{
			if(operation==1) point2=1;
			else point1=1;		
			power=1;
		}
		else if(point1==0 && operation==0) x1=x1*10+str[i]-'0';
		else if(point1==1 && operation==0) 
		{
			power*=0.1;
			x1+=(str[i]-'0')*power; 
	  }
		//程序跑到这里运算符必定加载
		else if(point2==0) x2=x2*10+str[i]-'0';
		else if(point2==1) 
		{
			power*=0.1;
			x2+=(str[i]-'0')*power;
		}
		else 
		{
			x1=0;
			x2=0;
			lcd_gotoxy(1,0);
			lcd_printstr("unexp error");
			lcd_delay(1000);
		}
	}
	switch(action)
	{
		case '+': y=x1+x2;break;
		case '-': y=x1-x2;break;
		case '*': y=x1*x2;break;
		case '/': y=x1/x2;break;//x2=0,y=+INF
		default: y=x1;break;
	}
		clearStr(str,17);
		sprintf(str,"%.6f",y);
		lcd_gotoxy(1,0);
		lcd_printstr(str);
		(*index)=-1;
		point1=0;
		point2=0;
		operation=0;
		action=0;
}