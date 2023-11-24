#include "keyboard.h"
unsigned char code key_board_table[16]="123+456-789*0.=/";
unsigned char dep_table[8]="dc#$%&()";
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
				while(KEY!=0xff);return dep_table[0];
			}
			case 0xfd:
			{
				while(KEY!=0xfd);return dep_table[1];
			}
			default:return 255;
		}
	}

	KEY=0xf0;//列4行4
	if(KEY!=0xf0){
		key_delay(20);
	if(KEY!=0xf0)
	{
		switch(KEY)//列扫描
		{
			case 0xe0:sum=1;break;
			case 0xd0:sum=2;break;
			case 0xb0:sum=3;break;
			case 0x70:sum=4;break;
		}
		KEY=0x0f;
		switch(KEY)//行扫描
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
