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
	float power=1;//�����Ȩ
	
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
		else if(str[i]=='.')//�����������������ֵ��
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
		//�����ܵ�����������ض�����
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
void calculator(unsigned char *str,unsigned char *index,unsigned char press)
{
	  if(end_mark)
		{
			lcd_init();
			end_mark=0;
		}
		else if(press=='=') 
		{
			getAnswer(str,index);
			end_mark=1;//������������������㲢��ʼ��
		}
		else if(press=='d') delStr(str,index);
		else if(press=='c') 
		{
			lcd_init();
			clearStr(str,17);
			(*index)=-1;
		}
		else addStr(str,index,press);
}
bh_delStr(unsigned char *str,unsigned char *index)
{
	if((*index)==-1)
	{
		lcd_init();
		lcd_printstr("space null");
		lcd_delay(1000);
	}
	else
	{
		str[*index]=0;//�����ַ�0������0
		(*index)--;
	}	
}
//�����Ƶ�ʮ�����ƶ�̬��ʾ
void binToHEX(unsigned char *str,unsigned char *index,unsigned char press)
{
	unsigned int BI=0x0000;//���ڴ洢16λ��������
	unsigned char HE[6]={0};//���ڴ洢4λʮ������������׺H
	char i,j,tmp;
	if(press=='d') bh_delStr(str,index);//��ɾ����������������
	else if(press=='c')
	{
		lcd_init();
		clearStr(str,17);
		(*index)=-1;
		return;
	}
	else if(press!='0'&&press!='1')
	{
		lcd_init();
		lcd_printstr("invalid input");
		lcd_delay(500);
	}
	
	//add str
	else 
	{
		if(*index==15) 
	  {
		  lcd_init();
		  lcd_printstr("space overflower");
		  lcd_delay(1000);
	  }
	  else
	  {
		  (*index)++;
		  str[*index]=press;
	  }
	}
/*=============================================
	=============�����=========================
	=========Ϊʲôindex=-1�ͻ�����================*/
	if(*index==-1)
	{
		lcd_init();
		return;
	}
	/*===========================================*/
	for(i=0;i<=(*index);i++)
	{
		BI=(BI<<1)+str[i]-'0';
	}//BI����
		//16->4��ּ���
/* 
----<-------------------<-------------------------<---------press���Ʒ���BI
	___________ tmp_____________tmp_________tmp________tmp__
  BI|15	14	13	12||||11	10	9	8||||7	6	5	4||||3	2	1	0|||
		--------------||||-----------||||--------||||--------|||
	i |     HE[0]   ||||    HE[1]  ||||   HE[2]||||  HE[3] |||
		--------------||||-----------||||--------||||--------|||
		*/
	for(i=0;i<4;i++)
	{
		tmp=(3-i)*4;//tmpָ��
		for(j=tmp;j<tmp+4;j++)
		{
			HE[i]+=((BI>>j)&1)<<(j-tmp);
		}
		if(HE[i]>=0&&HE[i]<=9) HE[i]+='0';
		else if(HE[i]>=10) HE[i]=HE[i]-10+'A';
		HE[4]='H';
	}
	lcd_init();
	lcd_printstr(str);
	lcd_gotoxy(1,0);
	lcd_printstr(HE);
}