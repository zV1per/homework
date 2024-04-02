#include <REGX52.H>
#include "Uart.h"

void UART_Init()
{
	SCON=0x50;
	PCON |= 0x80;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TL1 = 0xF3;		
	TH1 = 0xF3;		
	ET1 = 0;		
	TR1 = 1;		
	EA=1;
	ES=1;
}

void Uart_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}
