#include "Buzzer.h"
#include "Delay.h"

sbit BUZZER=P2^5;

void Buzzer(unsigned int xms)
{
	unsigned int i=0;
	for(;i<xms;i++)
	{
		BUZZER=!BUZZER;
		Delay(1);
	}
}
