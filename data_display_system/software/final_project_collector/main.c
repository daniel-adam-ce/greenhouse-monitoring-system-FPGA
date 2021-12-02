#include <stdio.h>
#include <stdint.h>
#include <io.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"

int main ()
{
	IOWR(SPI_0_BASE, 0x1, 0x7);
	int temp;
	for(int i = 0; i < 10000000; i++) {}
	while(1)
	{
		if(IORD(SPI_0_BASE, 0x2) & 0b10000000)
		{
			printf("test\n");
			temp = IORD(SPI_0_BASE, 0x0);
			printf("%i\n", temp);
		}
	}
}
