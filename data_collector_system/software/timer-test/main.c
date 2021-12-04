#include <stdio.h>
#include <stdint.h>
#include <io.h>
#include <math.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"



void timer_int_handler()
{
	printf("interrupt\n");
	IOWR(TIMER_0_BASE, 0, 0);
	return;
}

static void pio_init()
{

	IOWR(TIMER_0_BASE, 1, 8);
	IOWR(TIMER_0_BASE, 3, 250);
	IOWR(TIMER_0_BASE, 1, 7);
	alt_irq_register(TIMER_0_IRQ, TIMER_0_BASE, timer_int_handler);

	return;
}

int main()
{
	pio_init();

	IOWR(SEVEN_SEG_0_BASE, 0, 0xFFFFFFFF);
	IOWR(SEVEN_SEG_1_BASE, 0, 0xFFFFFFFF);

	return 0;
}
