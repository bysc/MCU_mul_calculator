#ifndef SYSTEM_H
#define SYSTEM_H
#include <reg51.h>
#include <stdio.h>
#include "lcd1602.h"
#include "keyboard.h"
#include <string.h>

void welcome();
void clearStr(unsigned char *str,unsigned char len);
void addStr(unsigned char *str,unsigned char *index,unsigned char press);
void getAnswer(unsigned char *str,unsigned char *index);
#endif