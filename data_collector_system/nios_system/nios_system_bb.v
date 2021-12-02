
module nios_system (
	clk_clk,
	i2c_serial_sda_in,
	i2c_serial_scl_in,
	i2c_serial_sda_oe,
	i2c_serial_scl_oe,
	keys_export,
	leds_g_export,
	leds_r_export,
	reset_reset,
	sdram_addr,
	sdram_ba,
	sdram_cas_n,
	sdram_cke,
	sdram_cs_n,
	sdram_dq,
	sdram_dqm,
	sdram_ras_n,
	sdram_we_n,
	sdram_clk_clk,
	seven_seg_0_export,
	seven_seg_1_export,
	switches_export,
	spi_0_serial_MISO,
	spi_0_serial_MOSI,
	spi_0_serial_SCLK,
	spi_0_serial_SS_n);	

	input		clk_clk;
	input		i2c_serial_sda_in;
	input		i2c_serial_scl_in;
	output		i2c_serial_sda_oe;
	output		i2c_serial_scl_oe;
	input	[3:0]	keys_export;
	output	[7:0]	leds_g_export;
	output	[31:0]	leds_r_export;
	input		reset_reset;
	output	[11:0]	sdram_addr;
	output	[1:0]	sdram_ba;
	output		sdram_cas_n;
	output		sdram_cke;
	output		sdram_cs_n;
	inout	[31:0]	sdram_dq;
	output	[3:0]	sdram_dqm;
	output		sdram_ras_n;
	output		sdram_we_n;
	output		sdram_clk_clk;
	output	[31:0]	seven_seg_0_export;
	output	[31:0]	seven_seg_1_export;
	input	[31:0]	switches_export;
	input		spi_0_serial_MISO;
	output		spi_0_serial_MOSI;
	output		spi_0_serial_SCLK;
	output		spi_0_serial_SS_n;
endmodule
