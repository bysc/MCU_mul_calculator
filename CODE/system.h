#ifndef SYSTEM_H
#define SYSTEM_H
#include <reg51.h>
#include <stdio.h>
#include "lcd1602.h"
#include "keyboard.h"
#include <string.h>
extern bit end_mark;
void welcome();
void clearStr(unsigned char *str,unsigned char len);
void addStr(unsigned char *str,char *index,unsigned char press);
void delStr(unsigned char *str,char *index);
void getAnswer(unsigned char *str,char *index);
void calculator(unsigned char *str,char *index,unsigned char press);
bh_delStr(unsigned char *str,char *index);
void binToHEX(unsigned char *str,char *index,unsigned char press);
#endif