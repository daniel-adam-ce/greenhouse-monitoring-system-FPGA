#include <stdio.h>
#include <stdint.h>
#include <io.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"

// *********************************************************************
// Variables used for calibration and compensating sensor data
long signed int t_fine;
unsigned short dig_T1 = 0;
signed short dig_T2 = 0;
signed short dig_T3 = 0;

unsigned short dig_P1 = -1;
signed short dig_P2 = 0;
signed short dig_P3 = 0;
signed short dig_P4 = 0;
signed short dig_P5 = 0;
signed short dig_P6 = 0;
signed short dig_P7 = 0;
signed short dig_P8 = 0;
signed short dig_P9 = 0;

unsigned char dig_H1 = 0;
signed short dig_H2 = 0;
unsigned char dig_H3 = 0;
signed short dig_H4 = 0;
signed short dig_H5 = 0;
signed char dig_H6 = 0;
// *********************************************************************

// SPI input and output bytes
uint8_t test_input[20];
uint8_t test_output[20];

// PERIOD global values
int PERIOD_INIT = 250;
int PERIOD = 5000;
// SETUP state flag
int SETUP = 0;

// Sensor result data
long signed int t_result = 0;
long unsigned int p_result = 0;
float p_result_float = 0;
long unsigned int h_result = 0;
float h_result_float = 0;

// Convert float into IEEE754 format to be sent
union float_by_bit {
	int i;
	float f;
};

// Compensate ADC temperature input function (from data sheet)
long signed int BME280_compensate_T_int32(long signed int adc_T)
{
    long signed int var1, var2, T;
    var1 = ((((adc_T>>3) - ((long signed int)dig_T1<<1))) * ((long signed int)dig_T2)) >> 11;
    var2 = (((((adc_T>>4) - ((long signed int)dig_T1)) * ((adc_T>>4) - ((long signed int)dig_T1))) >> 12) * ((long signed int)dig_T3)) >> 14;
    t_fine = var1 + var2;
    T = (t_fine * 5 + 128) >> 8;
    return T;
}

// Compensate ADC pressure input from data sheet
long unsigned int BME280_compensate_P_int64(long unsigned int adc_P)
{
	long long signed int var1, var2, p;
	var1 = ((long long signed int)t_fine) - 128000;
	var2 = var1 * var1 * (long long signed int)dig_P6;
	var2 = var2 + ((var1*(long long signed int)dig_P5)<<17);
	var2 = var2 + (((long long signed int)dig_P4)<<35);
	var1 = ((var1 * var1 * (long long signed int)dig_P3)>>8) + ((var1 * (long long signed int)dig_P2)<<12);
	var1 = (((((long long signed int)1)<<47)+var1))*((long long signed int)dig_P1)>>33;
	if (var1 == 0)
	{
		return 0; // avoid exception caused by division by zero
	}
	p = 1048576-adc_P;
	p = (((p<<31)-var2)*3125)/var1;
	var1 = (((long long signed int)dig_P9) * (p>>13) * (p>>13)) >> 25;
	var2 = (((long long signed int)dig_P8) * p) >> 19;
	p = ((p + var1 + var2) >> 8) + (((long long signed int)dig_P7)<<4);
	return (long unsigned int)p;
}

// Compensate ADC humidity input from data sheet
long unsigned int bme280_compensate_H_int32(long signed int adc_H)
{
	long signed int v_x1_u32r;
	v_x1_u32r = (t_fine - ((long signed int)76800));
	v_x1_u32r = (((((adc_H << 14) - (((long signed int)dig_H4) << 20) - (((long signed int)dig_H5) * v_x1_u32r)) +
	((long signed int)16384)) >> 15) * (((((((v_x1_u32r * ((long signed int)dig_H6)) >> 10) * (((v_x1_u32r *
	((long signed int)dig_H3)) >> 11) + ((long signed int)32768))) >> 10) + ((long signed int)2097152)) *
	((long signed int)dig_H2) + 8192) >> 14));
	v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * ((long signed int)dig_H1)) >> 4));
	v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
	v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);
	return (long unsigned int)(v_x1_u32r>>12);
}

// Set up BME sensor
void bme_init()
{
	IOWR(BME_SCK_BASE, 0, 0);	//Initializes clock to 0
	IOWR(BME_CSN_BASE, 0, 1);	//Initializes csn to 1
}

// SPI communication function for BME sensor
void spi_comm (uint8_t input[], uint8_t output[], int in_length, int out_length)
{
	for(int i = 0; i < out_length; i++)	//Initializing output array to all zeros
	{
		output[i] = 0;
	}

	IOWR(BME_CSN_BASE, 0, 0);	//CSN to 0 to begin comm
	for(int i = 0; i < ((in_length > out_length)?in_length:out_length); i++)	//Loop once for each byte of communication
	{
		for(int j = 7; j >= 0; j--)	//Loop 8 times for each byte
		{
			IOWR(BME_SCK_BASE, 0, 0);	//Clock falling edge
			if(i < in_length)	//Change input byte (if still inputting)
				IOWR(BME_MOSI_BASE, 0, (input[i] & (1 << j))?1:0);
			if(i < out_length)	//Change output byte (if still outputting)
				output[i] = output[i] | (IORD(BME_MISO_BASE, 0) << j);
			IOWR(BME_SCK_BASE, 0, 1);	//Clock rising edge (when input is read by transceiver
		}
	}
	IOWR(BME_SCK_BASE, 0, 0);	//Reset clock back to 0
	IOWR(BME_CSN_BASE, 0, 1);	//Reset CSN back to 1, ending communication
}

// SPI communication for NRF transmitter
void spi_comm_nrf(uint8_t input[], uint8_t output[], int in_length, int out_length)
{
	for(int i = 0; i < out_length; i++)	//Initializing output array to all zeros
	{
		output[i] = 0;
	}

	IOWR(NRF_CSN_BASE, 0, 0);	//CSN to 0 to begin comm
	for(int i = 0; i < ((in_length > out_length)?in_length:out_length); i++)	//Loop once for each byte of communication
	{
		for(int j = 7; j >= 0; j--)	//Loop 8 times for each byte
		{
			IOWR(NRF_SCK_BASE, 0, 0);	//Clock falling edge
			if(i < in_length)	//Change input byte (if still inputting)
				IOWR(NRF_MOSI_BASE, 0, (input[i] & (1 << j))?1:0);
			if(i < out_length)	//Change output byte (if still outputting)
				output[i] = output[i] | (IORD(NRF_MISO_BASE, 0) << j);
			IOWR(NRF_SCK_BASE, 0, 1);	//Clock rising edge (when input is read by transceiver
		}
	}
	IOWR(NRF_SCK_BASE, 0, 0);	//Reset clock back to 0
	IOWR(NRF_CSN_BASE, 0, 1);	//Reset CSN back to 1, ending communication
}

// Set up NRF transmitter
void nrf_init() {

	// setting CLK to 0 and setting CSN to 1
	IOWR(NRF_SCK_BASE, 0, 0);
	IOWR(NRF_CSN_BASE, 0, 1);

	// setting auto ACK
	test_input[0] = 0b00111101;
	test_input[1] = 0x6;
	spi_comm_nrf(test_input, test_output, 2, 0);

	// flushing TX FIFO
	test_input[0] = 0b11100001;
	spi_comm_nrf(test_input, test_output, 1, 0);

	// setting status register
	test_input[0] = 0x27;
	test_input[1] = 0x1E;
	spi_comm_nrf(test_input, test_output, 2, 0);

}

// Print sensor data and compensate the data
void print_array_v (int8_t a[], int size)
{
	if(size > 1)
	{
		printf("Received Sensor Data: ");
		for(int i = 0; i < size - 1; i++)
		{
			alt_printf("%x, ", (a[i] & 0xFF));
		}
	}
	alt_printf("%x\n", (a[size - 1] & 0xFF));

	// temperature
	long signed int t = 0;
	t = (a[4] << 12) + (a[5] << 4) + a[6];
	t = t & 0x000FFFFF;
	t_result = BME280_compensate_T_int32(t);
	printf("compensated T: %g\n", t_result * 0.01);

	// pressure
	long signed int p = 0;
	p = (a[1] << 12) + (a[2] << 4) + a[3];
	p = p & 0x000FFFFF;
	p_result = BME280_compensate_P_int64(p);
	p_result_float = ((float)p_result/256);
	printf("compensated P: %g\n", p_result_float);

	// humidity
	long signed int h = 0;
	h = (a[7] << 8) + a[8];
	h = h & 0xFFFF;
	h_result = bme280_compensate_H_int32(h);
	h_result_float = ((float)h_result / 1024);
	printf("compensated H: %g\n", h_result_float);
	return;
}

// Timer interrupt handler
void timer_int_handler()
{
	if (SETUP == 1) {

		// secondary setup
		// writing to ctrl_hum
		// setting osrs_h to 100
		test_input[0] = 0x72;
		test_input[1] = 0x04;
		spi_comm(test_input, test_output, 2, 0);

		// reading calib data for temperature
		test_input[0] = 0x88;
		spi_comm(test_input, test_output, 1, 7);
		dig_T1 = (test_output[2] << 8) + (test_output[1]);
		dig_T2 = (test_output[4] << 8) + (test_output[3]);
		dig_T3 = (test_output[6] << 8) + (test_output[5]);
//		printf("%x %x %x\n", dig_T1, dig_T2, dig_T3);

		// reading calib data for pressure
		test_input[0] = 0x8E;
		spi_comm(test_input, test_output, 1, 19);

		dig_P1 = ((test_output[2] << 8) + (test_output[1])) & 0xFFFF;
		dig_P2 = (test_output[4] << 8) + (test_output[3])& 0xFFFF;
		dig_P3 = ((test_output[6] << 8) + (test_output[5]))& 0xFFFF;
		dig_P4 = ((test_output[8] << 8) + (test_output[7]))& 0xFFFF;
		dig_P5 = ((test_output[10] << 8) + (test_output[9]))& 0xFFFF;
		dig_P6 = ((test_output[12] << 8) + (test_output[11]))& 0xFFFF;
		dig_P7 = ((test_output[14] << 8) + (test_output[13]))& 0xFFFF;
		dig_P8 = ((test_output[16] << 8) + (test_output[15]))& 0xFFFF;
		dig_P9 = ((test_output[18] << 8) + (test_output[17]))& 0xFFFF;


		// reading calib data for humidity
		test_input[0] = 0xA1;
		spi_comm(test_input, test_output, 1, 2);

		dig_H1 = test_output[1];
		test_input[0] = 0xE1;
		spi_comm(test_input, test_output, 1, 8);

		dig_H2 = (test_output[2] << 8) + (test_output[1])& 0xFFFF;
		dig_H3 = test_output[3];
		dig_H4 = (test_output[4] << 4) + (test_output[5] & 0x0F)& 0xFFF;
		dig_H5 = (test_output[6] << 4) + (test_output[5] & 0xF0)& 0xFFF;
		dig_H6 = test_output[7];

		SETUP = 2;
		IOWR(TIMER_0_BASE, 1, 8);
		IOWR(TIMER_0_BASE, 3, PERIOD);
		IOWR(TIMER_0_BASE, 1, 7);
	} else if (SETUP == 2) {
		// tx mode
		test_input[0] = 0b00100000;
		test_input[1] = 0b00001010; // power up
		spi_comm_nrf(test_input, test_output, 2, 0);
		SETUP = 3;

		IOWR(TIMER_0_BASE, 3, 2);
		IOWR(TIMER_0_BASE, 1, 7);
	} else if (SETUP == 3) {
		// get Sensor data
		IOWR(TIMER_0_BASE, 1, 8);
		test_input[0] = 0xF7;
		spi_comm(test_input, test_output, 1, 9);
		print_array_v(test_output, 9);


		IOWR(NRF_CE_BASE, 0, 1);
		int j =0;
		// delay at least 130us
		for (int i = 0; i < 10000; i++) {
			j = 1;
		}
		test_input[0] = 0b10100000;
		union float_by_bit p;
		p.f = p_result_float;
		union float_by_bit h;
		h.f = h_result_float;
		// Moving result data into bytes
		test_input[1] = (t_result >> 24) & 0xFF;
		test_input[2] = (t_result >> 16) & 0xFF;
		test_input[3] = (t_result >> 8) & 0xFF;
		test_input[4] = (t_result >> 0) & 0xFF;
		test_input[5] = (p.i >> 24) & 0xFF;
		test_input[6] = (p.i >> 16) & 0xFF;
		test_input[7] = (p.i >> 8) & 0xFF;
		test_input[8] = (p.i >> 0) & 0xFF;
		test_input[9] = (h.i >> 24) & 0xFF;
		test_input[10] = (h.i >> 16) & 0xFF;
		test_input[11] = (h.i >> 8) & 0xFF;
		test_input[12] = (h.i >> 0) & 0xFF;
		printf("Transmitted data: ");
		for (int i = 0; i < 13; i++) {
			printf("%x ", test_input[i]);
		}
		printf("\n");
		spi_comm_nrf(test_input, test_output, 13, 0);

		SETUP = 4;
		IOWR(TIMER_0_BASE, 3, 1);
		IOWR(TIMER_0_BASE, 1, 7);
	} else if (SETUP == 4) {
		IOWR(TIMER_0_BASE, 1, 8);
		IOWR(NRF_CE_BASE, 0, 0);
		IOWR(TIMER_0_BASE, 3, PERIOD);
		IOWR(TIMER_0_BASE, 1, 7);

		test_input[0] = 0xFF;
		spi_comm_nrf(test_input, test_output, 1, 1);
		printf("Status: %x\n\n", test_output[0]);

		test_input[0]=0x27;
		test_input[1]=0x2E;
		spi_comm_nrf(test_input, test_output, 2, 0);
		SETUP = 2;
	}
	IOWR(TIMER_0_BASE, 0, 0);
	return;
}

// Set up PIOs
static void pio_init()
{

	IOWR(SEVEN_SEG_0_BASE,0, -1);
	IOWR(SEVEN_SEG_1_BASE, 0, -1);
	IOWR(LEDS_R_BASE, 0, 0);
	IOWR(LEDS_G_BASE, 0, 0);
	IOWR(TIMER_0_BASE, 1, 8);
	IOWR(TIMER_0_BASE, 3, PERIOD_INIT);
	IOWR(TIMER_0_BASE, 1, 7);
	alt_irq_register(TIMER_0_IRQ, TIMER_0_BASE, timer_int_handler);

	return;
}

// Main function
int main ()
{

	// initializing PIOs
	pio_init();
	bme_init();
	nrf_init();

	// initial setup
	// writing to crtl_meas to set up osrs_t and osrs_p and set mode
	// osrs_t = 001, osrs_p = 001, mode = 11
	test_input[0] = 0x74;
	test_input[1] = 0x27;
	spi_comm(test_input, test_output, 2, 0);
	SETUP = 1;

	return 0;
}
