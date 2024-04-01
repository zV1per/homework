#include "Led.h"
#include "Delay.h"
#include <REGX52.h>

void Led(unsigned char i)
{
	P2_0=!((0x01<<0)&i);
	P2_1=!((0x01<<1)&i);
	P2_2=!((0x01<<2)&i);
	P2_3=!((0x01<<3)&i);
	P2_4=!((0x01<<4)&i);
	P2_5=!((0x01<<5)&i);
	P2_6=!((0x01<<6)&i);
	P2_7=!((0x01<<7)&i);
	
}

