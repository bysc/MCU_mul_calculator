#ifndef LCD1602_H
#define LCD1602_H
#include <reg51.h>
#include <stdio.h>
#define LCD P0
//LCD1602的三个控制端
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P2^5;
//延时函数
void lcd_delay(unsigned int times);
//写指令
void lcd_writecmd(unsigned char cmd);
//写入数据
void lcd_writedata(unsigned char mydata);
//输出字符串
void lcd_printstr(unsigned char*str);
//显示屏开启
void lcd_turnon();
//显示屏关闭
void lcd_turnoff();
//显示屏初始化
void lcd_init();
//光标定位
void lcd_gotoxy(unsigned char x,unsigned char y);//0-1,0-15

#endif