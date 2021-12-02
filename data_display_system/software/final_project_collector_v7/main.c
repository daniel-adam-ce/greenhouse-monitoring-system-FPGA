#include <stdio.h>
#include <stdint.h>
#include <io.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_lcd_16207_regs.h"
#include "altera_avalon_lcd_16207.h"
#include "sys/alt_irq.h"

//NRF_CSN_BASE, NRF_SCK_BASE, NRF_MOSI_BASE, NRF_MISO_BASE, NRF_CE_BASE, NRF_IRQ_BASE

void nrf_init()
{
	IOWR(NRF_SCK_BASE, 0, 0);
	IOWR(NRF_CSN_BASE, 0, 1);
	//alt_irq_register(NRF_IRQ_IRQ, NRF_IRQ_BASE, nrf_int_handler);
}

void spi_comm (int8_t input[], int8_t output[], int in_length, int out_length)
{
	for(int i = 0; i < out_length; i++)
	{
		output[i] = 0;
	}

	IOWR(NRF_CSN_BASE, 0, 0);
	for(int i = 0; i < ((in_length > out_length)?in_length:out_length); i++)
	{
		for(int j = 7; j >= 0; j--)
		{
			IOWR(NRF_SCK_BASE, 0, 0);
			if(i < in_length)
				IOWR(NRF_MOSI_BASE, 0, (input[i] & (1 << j))?1:0);
			if(i < out_length)
				output[i] = output[i] | (IORD(NRF_MISO_BASE, 0) << j);
			IOWR(NRF_SCK_BASE, 0, 1);
		}
	}
	IOWR(NRF_SCK_BASE, 0, 0);
	IOWR(NRF_CSN_BASE, 0, 1);
}

void print_array (int8_t a[], int size)
{
	if(size > 1)
	{
		for(int i = 0; i < size - 1; i++)
		{
			alt_printf("%x, ", (a[i] & 0xFF));
		}
	}
	alt_printf("%x\n", (a[size - 1] & 0xFF));
}

int main ()
{
	IOWR(SEVEN_SEG_0_BASE, 0, 0xFFFFFFFF);
	IOWR(SEVEN_SEG_1_BASE, 0, 0xFFFFFFFF);

	/*nrf_init();

	int8_t test_input[10];
	int8_t test_output[10];

	test_input[0] = 0xB;
	spi_comm(test_input, test_output, 1, 6);
	print_array(test_output, 6);*/
}
