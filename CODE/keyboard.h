#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <reg51.h>
#include <stdio.h>
#define KEY P3
//»ñÈ¡¼üÅÌÖµ
unsigned char key_getvalue();
void key_delay(unsigned int times);
#endif