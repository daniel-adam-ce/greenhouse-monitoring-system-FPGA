#include <stdio.h>
#include <stdint.h>
#include <io.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"
#include <altera_up_sd_card_avalon_interface.h>
#include "altera_up_avalon_character_lcd.h"

#define SD_ASR (SD_CARD_INTERFACE_BASE + 564*8)
#define FILE_NAME "data.txt"

int display = 0; // 0 = temp, 1 = humidity, 2 = pressure
int index = 0;
int max_index = 0;
float temperature, humidity, pressure;
int use_data_prompt = 0;
int no_response = 1;
int response;
int waiting = 0;
uint8_t nrf_input[33];
uint8_t nrf_output[33];

union float_by_bit {
	int i;
	float f;
};

alt_up_character_lcd_dev * char_lcd_dev;

//NRF_CSN_BASE, NRF_SCK_BASE, NRF_MOSI_BASE, NRF_MISO_BASE, NRF_CE_BASE, NRF_IRQ_BASE

void spi_comm(uint8_t input[], uint8_t output[], int in_length, int out_length)
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

void print_array(int8_t a[], int size)
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

void lcd_print(char string0[], char string1[])
{
	alt_up_character_lcd_init(char_lcd_dev);
	alt_up_character_lcd_string(char_lcd_dev, string0);
	alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 1);
	alt_up_character_lcd_string(char_lcd_dev, string1);
}

void sd_write_data()
{
	union float_by_bit n;
	max_index++;
	short int handle = alt_up_sd_card_fopen(FILE_NAME, false);
	alt_up_sd_card_write(handle, max_index);
	for(int i = 0; i < max_index * 12; i++) {alt_up_sd_card_read(handle);}
	n.f = temperature;
	for(int i = 3; i >= 0; i--) {alt_up_sd_card_write(handle, (n.i >> (i*8)));}
	n.f = humidity;
	for(int i = 3; i >= 0; i--) {alt_up_sd_card_write(handle, (n.i >> (i*8)));}
	n.f = pressure;
	for(int i = 3; i >= 0; i--) {alt_up_sd_card_write(handle, (n.i >> (i*8)));}
	alt_up_sd_card_fclose(handle);

	if(index == max_index - 2)
	{
		index++;
		update_lcd();
	}

	if(max_index == 1)
		update_lcd();
}

void sd_read_data()
{
	union float_by_bit n;
	short int handle = alt_up_sd_card_fopen(FILE_NAME, false);
	alt_up_sd_card_read(handle);
	for(int i = 0; i < index * 12 + 12; i++) {alt_up_sd_card_read(handle);}
	n.i = 0;
	for(int i = 3; i >= 0; i--) {n.i = n.i | (alt_up_sd_card_read(handle) << (i*8));}
	temperature = n.f;
	n.i = 0;
	for(int i = 3; i >= 0; i--) {n.i = n.i | (alt_up_sd_card_read(handle) << (i*8));}
	humidity = n.f;
	n.i = 0;
	for(int i = 3; i >= 0; i--) {n.i = n.i | (alt_up_sd_card_read(handle) << (i*8));}
	pressure = n.f;
	alt_up_sd_card_fclose(handle);
}

void update_lcd()
{
	if(max_index == 0)
	{
		lcd_print("No data", "available yet.");
		return;
	}
	char *temp0 = (char*)malloc(16 * sizeof(char));
	char *temp1 = (char*)malloc(16 * sizeof(char));
	switch(display) {
		case 0:
			sprintf(temp0, "Temperature at");
			sprintf(temp1, "t=%d: %g C", index, temperature);
			lcd_print(temp0, temp1);
			break;
		case 1:
			sprintf(temp0, "Humidity at");
			sprintf(temp1, "t=%d: %g%%", index, humidity);
			lcd_print(temp0, temp1);
			break;
		case 2:
			sprintf(temp0, "Pressure at");
			sprintf(temp1, "t=%d: %g Pa", index, pressure);
			lcd_print(temp0, temp1);
			break;
	}
}

void key_int_handler()
{
	int state = IORD(KEYS_BASE, 0);
	if(!(state & 2))
	{
		//alt_printf("KEY1\n");
		char *temp = (char*)malloc(16 * sizeof(char));
		if(display == 2)
			display = 0;
		else
			display++;
		sd_read_data();
		update_lcd();
	}
	else if(!(state & 4))
	{
		//alt_printf("KEY2\n");
		if(use_data_prompt)
		{
			no_response = 0;
			response = 0;
			return;
		}
		if(index < max_index - 1)
		{
			index++;
			sd_read_data();
			update_lcd();
		}
	}
	else if(!(state & 8))
	{
		//alt_printf("KEY3\n");
		if(use_data_prompt)
		{
			no_response = 0;
			response = 1;
			return;
		}
		if(index > 0)
		{
			index--;
			sd_read_data();
			update_lcd();
		}
	}
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE + 3, 0x0);
}

void timer_int_handler()
{
	waiting = 0;
	IOWR(TIMER_0_BASE, 0, 0);
}

void nrf_int_handler()
{
	union float_by_bit n;

	//Reading RX payload
	nrf_input[0] = 0b01100001;
	spi_comm(nrf_input, nrf_output, 1, 13);
	//print_array(nrf_output, 13);

	unsigned int temp = 0;
	for(int i = 0; i < 4; i++)
	{
		temp = temp | (nrf_output[i + 1] << (3-i)*8);
	}
	temperature = temp * 0.01;
	//alt_printf("Temperature: %x\n", temp);
	temp = 0;
	for(int i = 0; i < 4; i++)
	{
		temp = temp | (nrf_output[i + 5] << (3-i)*8);
	}
	n.i = temp;
	pressure = n.f;
	//alt_printf("Pressure: %x\n", temp);
	temp = 0;
	for(int i = 0; i < 4; i++)
	{
		temp = temp | (nrf_output[i + 9] << (3-i)*8);
	}
	n.i = temp;
	humidity = n.f;
	//alt_printf("Humidity: %x\n", temp);

	//Resetting status register
	nrf_input[0] = 0x27;
	nrf_input[1] = 0x4E;
	spi_comm(nrf_input, nrf_output, 2, 1);

	printf("%g, %g, %g\n", temperature, pressure, humidity);

	sd_write_data();

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(NRF_IRQ_BASE + 3, 0x0);
}

static void irq_init()
{
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0xF);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE + 3, 0x0);
	alt_irq_register(KEYS_IRQ, KEYS_BASE + 3, key_int_handler);

	/*IOWR(TIMER_0_BASE, 1, 8);
	IOWR(TIMER_0_BASE, 0, 0);
	alt_irq_register(TIMER_0_IRQ, TIMER_0_BASE, timer_int_hander);
	IOWR(TIMER_0_BASE, 3, 250);
	IOWR(TIMER_0_BASE, 1, 7);
	alt_printf("IRQ initialized\n");*/

	return;
}

void nrf_init()
{
	IOWR(NRF_SCK_BASE, 0, 0);	//Initializes clock to 0
	IOWR(NRF_CSN_BASE, 0, 1);	//Initializes csn to 1

	//Turning on auto acknowledge
	nrf_input[0] = 0b00100001;
	nrf_input[1] = 1;
	spi_comm(nrf_input, nrf_output, 2, 1);

	//Resetting status register
	nrf_input[0] = 0x27;
	nrf_input[1] = 0x4E;
	spi_comm(nrf_input, nrf_output, 2, 1);

	//Resetting data pipe 0 byte count
	nrf_input[0] = 0x31;
	nrf_input[1] = 12;
	spi_comm(nrf_input, nrf_output, 2, 1);

	//Flushing RX FIFO
	nrf_input[0] = 0b11100010;
	spi_comm(nrf_input, nrf_output, 1, 1);

	//Enabling RX mode
	nrf_input[0] = 0b00100000;
	nrf_input[1] = 0b110010;
	spi_comm(nrf_input, nrf_output, 2, 1);

	IOWR(TIMER_0_BASE, 3, 2);
	IOWR(TIMER_0_BASE, 1, 7);
	waiting = 1;
	while(waiting) {}
	IOWR(TIMER_0_BASE, 1, 8);
	alt_printf("Standby-I mode\n");

	IOWR(NRF_CE_BASE, 0, 1);
	nrf_input[0] = 0b00100000;
	nrf_input[1] = 0b110011;
	spi_comm(nrf_input, nrf_output, 2, 1);
	alt_printf("RX mode\n");
}

void lcd_init()
{
	// open the Character LCD port
	char_lcd_dev = alt_up_character_lcd_open_dev ("/dev/character_lcd");
	if ( char_lcd_dev == NULL)
		alt_printf ("Error: could not open character LCD device\n");
	else
		alt_printf ("Opened character LCD device\n");

	/* Initialize the character display */
	alt_up_character_lcd_init (char_lcd_dev);
}

void sd_init()
{
	alt_up_sd_card_dev *device_reference = NULL;
	device_reference = alt_up_sd_card_open_dev("/dev/sd_card_interface");
	if (device_reference != NULL) {
		if (alt_up_sd_card_is_Present()) {
			alt_printf("Card connected\n");
			if (alt_up_sd_card_is_FAT16()) {
				alt_printf("FAT16 file system detected\n");
			} else {
				alt_printf("Unknown file system\n");
			}
		} else if (!alt_up_sd_card_is_Present()) {
			lcd_print("Please insert an", "SD card.");
			while(!alt_up_sd_card_is_Present()) {}
			lcd_print("", "");
			alt_printf("Card connected\n");
			if (alt_up_sd_card_is_FAT16()) {
				alt_printf("FAT16 file system detected\n");
			} else {
				alt_printf("Unknown file system\n");
			}
		}
	}

	short int handle = alt_up_sd_card_fopen(FILE_NAME, false);
	int start = alt_up_sd_card_read(handle);
	if(start > 0 && start < 65535)
		{
			lcd_print("Existing data", "found. Use it?");
			use_data_prompt = 1;
			while(no_response) {}
			use_data_prompt = 0;
			if(response)
			{
				alt_printf("Existing data used\n");
				max_index = start;
				index = max_index - 1;
				alt_up_sd_card_fclose(handle);
				sd_read_data();
			}
			else
			{
				alt_up_sd_card_fclose(handle);
				handle = alt_up_sd_card_fopen(FILE_NAME, false);
				alt_up_sd_card_write(handle, 0);
				max_index = 0;
				alt_up_sd_card_fclose(handle);
			}
		}
		else
		{
			alt_up_sd_card_fclose(handle);
			handle = alt_up_sd_card_fopen(FILE_NAME, false);
			alt_up_sd_card_write(handle, 0);
			max_index = 0;
			alt_up_sd_card_fclose(handle);
		}
		update_lcd();
}

int main()
{

	IOWR(SEVEN_SEG_0_BASE, 0, 0xFFFFFFFF);
	IOWR(SEVEN_SEG_1_BASE, 0, 0xFFFFFFFF);
	IOWR(LEDS_R_BASE, 0, 0);
	IOWR(LEDS_G_BASE, 0, 0);

	IOWR(TIMER_0_BASE, 1, 8);
	IOWR(TIMER_0_BASE, 0, 0);
	alt_irq_register(TIMER_0_IRQ, TIMER_0_BASE, timer_int_handler);

	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(NRF_IRQ_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(NRF_IRQ_BASE + 3, 0);
	alt_irq_register(NRF_IRQ_IRQ, NRF_IRQ_BASE + 3, nrf_int_handler);

	alt_printf("Waiting for nrf startup\n");
	IOWR(TIMER_0_BASE, 3, 150);
	IOWR(TIMER_0_BASE, 1, 7);
	waiting = 1;
	while(waiting){}
	alt_printf("Nrf started\n");

	irq_init();
	nrf_init();
	lcd_init();
	sd_init();
}
