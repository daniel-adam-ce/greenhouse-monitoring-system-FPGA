#include <stdio.h>
#include <stdint.h>
#include <io.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"

int8_t data;

int main ()
{
	IOWR(I2C_0_BASE, 0x2, 0);
	IOWR(I2C_0_BASE, 0, 0b1000000001);
	IOWR(I2C_0_BASE, 0x8, 0x1);
	IOWR(I2C_0_BASE, 0x9, 0x1);
	IOWR(I2C_0_BASE, 0xA, 0x1);
	IOWR(I2C_0_BASE, 0x3, 0x2);
	IOWR(I2C_0_BASE, 0x2, 0x1);

	while(1)
	{
		if(IORD(I2C_0_BASE, 0x4) & 2)
		{
			data = IORD(I2C_0_BASE, 0x1);
			printf("%i\n", data);
		}
	}
}
