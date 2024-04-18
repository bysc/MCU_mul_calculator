#include "keyboard.h"
unsigned char code key_board_table[16]="123+456-789*0.=/";
unsigned char dep_table[8]="dc#$%&(t";//456��������
void key_delay(unsigned int times)
{
	unsigned int i,j;
	for(i=0;i<times;i++)
		for(j=0;j<112;j++);
}
unsigned char key_getvalue()
{
	unsigned char sum=0;
	
	
	KEY=0xff;
	if(KEY!=0xff)
	{
		key_delay(20);
		if(KEY!=0xff) switch(KEY)
		{
			case 0xfe:
			{
				while(KEY!=0xff);return dep_table[0];break;
			}
			case 0xfd:
			{
				while(KEY!=0xff);return dep_table[1];break;
			}
			case 0xfb:
			{
				while(KEY!=0xff);return dep_table[2];break;
			}
			case 0xf7:
			{
				while(KEY!=0xff);return dep_table[3];break;
			}
			case 0xef:
			{
				while(KEY!=0xff);return dep_table[4];break;
			}	
			case 0xdf:
			{
				while(KEY!=0xff);return dep_table[5];break;
			}	
			case 0xbf:
			{
				while(KEY!=0xff);return dep_table[6];break;
			}				
			case 0x7f:
			{
				while(KEY!=0xff);return dep_table[7];break;
			}		
			default:return 255;break;
		}
	}
	KEY=0xf0;//��4��4
	if(KEY!=0xf0){
		key_delay(20);
	if(KEY!=0xf0)
	{
		switch(KEY)//�����ߣ���ɨ��
		{
			case 0xe0:sum=1;break;
			case 0xd0:sum=2;break;
			case 0xb0:sum=3;break;
			case 0x70:sum=4;break;
		}
		KEY=0x0f;
		switch(KEY)//��ɨ��
		{
			case 0x0e:sum=sum;break;
			case 0x0d:sum=sum+4;break;
			case 0x0b:sum=sum+8;break;
			case 0x07:sum=sum+12;break;			
		}
		while(KEY!=0x0f);
		return key_board_table[sum-1];
	}}
	else return 255;
}
