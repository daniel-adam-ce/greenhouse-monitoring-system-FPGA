#include <stdio.h>
#include <stdint.h>
#include <io.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"

int main ()
{
	IOWR(SPI_0_BASE, 0x3, 0b10000000000);
	IOWR(SPI_CE_BASE, 0x0, 1);
	for(int j = 0; j < 10000000; j++) {}

	//printf("%x\n", readTransReg(SPI_0_BASE, 0x7));
}

void printSPIStatus (int mask)
{
	int status = IORD(SPI_0_BASE, 0x2);
	printf("Status:\n");
	if(status & mask & (1 << 3))
		printf("\tReceive-overrun error\n");
	if(status & mask & (1 << 4))
		printf("\tTransmitter-overrun error\n");
	if(status & mask & (1 << 5))
		printf("\tTransmitter shift-register empty\n");
	if(status & mask & (1 << 6))
		printf("\tTransmitter ready\n");
	if(status & mask & (1 << 7))
		printf("\tReceiver ready\n");
	if(status & mask & (1 << 8))
		printf("\tError\n");
	if(status & mask & (1 << 9))
		printf("\tEnd of packet\n");
}

int8_t readTransReg (int spiBaseAddr, int8_t reg)
{
	int8_t temp;
	printSPIStatus(0b1111111000);
	IOWR(spiBaseAddr, 0x1, reg);
	for(int j = 0; j < 1000000; j++) {}
	while(1)
	{
		if(IORD(SPI_0_BASE, 0x2) & 0b10000000)
		{
			printSPIStatus(0b1111111000);
			temp = IORD(SPI_0_BASE, 0x0);// & 0b11111111;
			printSPIStatus(0b1111111000);
			break;
		}
	}
	return temp;
}
