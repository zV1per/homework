#include <REGX52.h>
#include "Delay.h"
#include <INTRINS.H>
#include "Led.h"
#include "Buzzer.h"
#include "Nixie.h"
#include "Tim.h"
#include "Uart.h"

void main()
{
	Uart_Init();
	while(1)
	{	
		//Buzzer(100);

		
		
//		Nixie(1,1);
//		Nixie(2,2);
//		Nixie(3,3);
//		Nixie(4,4);
		
		
//		for(i=0;i<8;i++)
//		{
//			Led(0x01<<i);Delay(500);
//		}
		
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		
	TH0 = 0xFC;		
	T0Count++;		
	if(T0Count>=500)
	{
		T0Count=0;
	}
}


void UART_Routine() interrupt 4
{
	if(RI==1)
	{
		Led(SBUF);
		RI=0;
	}
}
