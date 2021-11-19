#include <stdio.h>
#include <stdint.h>
#include <io.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"

int main ()
{
	while(1)
	{
		if(IORD(SPI_0_BASE, 0x2) & 0b10000000)
		{
			printf("%i", IORD(SPI_0_BASE, 0x0));
		}
	}
}
