#ifndef LCD1602_H
#define LCD1602_H
#include <reg51.h>
#include <stdio.h>
#define LCD P0
//LCD1602���������ƶ�
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P2^5;
//��ʱ����
void lcd_delay(unsigned int times);
//дָ��
void lcd_writecmd(unsigned char cmd);
//д������
void lcd_writedata(unsigned char mydata);
//����ַ���
void lcd_printstr(unsigned char*str);
//��ʾ������
void lcd_turnon();
//��ʾ���ر�
void lcd_turnoff();
//��ʾ����ʼ��
void lcd_init();
//��궨λ
void lcd_gotoxy(unsigned char x,unsigned char y);//0-1,0-15

#endif