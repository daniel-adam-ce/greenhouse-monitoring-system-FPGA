module final_project (CLOCK_50, KEY, SW, LEDR, LEDG, HEX0, HEX1, SDRAM_ADDR, SDRAM_BA, SDRAM_CAS_N, 
							SDRAM_CKE, SDRAM_CS_N, SDRAM_DQ, SDRAM_DQM, SDRAM_RAS_N, SDRAM_WE_N, SDRAM_CLK,
							I2C_SCL, I2C_SDA);
	input CLOCK_50;
	input [31:0] SW;
	input  [3:0] KEY;
	output [31:0] LEDR;
	output  [7:0] LEDG;
	output [31:0] HEX0;
	output [31:0] HEX1;
	output [11:0] SDRAM_ADDR;
	output [1:0]  SDRAM_BA;
	output        SDRAM_CAS_N;
	output        SDRAM_CKE;
	output        SDRAM_CS_N;
	inout  [31:0] SDRAM_DQ;
	output [3:0]  SDRAM_DQM;
	output        SDRAM_RAS_N;
	output        SDRAM_WE_N;
	output		  SDRAM_CLK;
	inout	tri1	  I2C_SCL;
	inout	tri1	  I2C_SDA;
	
	wire 		I2C_SCL_IN;
	wire		I2C_SCL_OE;
	wire		I2C_SDA_IN;
	wire		I2C_SDA_OE;
	
	assign	I2C_SCL_IN = I2C_SCL;
	assign 	I2C_SCL = I2C_SCL_OE ? 1'b0 : 1'bz;
	assign	I2C_SDA_IN = I2C_SDA;
	assign 	I2C_SDA = I2C_SDA_OE ? 1'b0 : 1'bz;
	
	nios_system NiosII (
		.clk_clk(CLOCK_50),
		.reset_reset(),
		.switches_export(SW),
		.keys_export(KEY),
		.leds_r_export(LEDR),
		.leds_g_export(LEDG),
		.seven_seg_0_export(HEX0),
		.seven_seg_1_export(HEX1),
		.sdram_addr(SDRAM_ADDR),
		.sdram_ba(SDRAM_BA),
		.sdram_cas_n(SDRAM_CAS_N),
		.sdram_cke(SDRAM_CKE),
		.sdram_cs_n(SDRAM_CS_N),
		.sdram_dq(SDRAM_DQ),
		.sdram_dqm(SDRAM_DQM),
		.sdram_ras_n(SDRAM_RAS_N),
		.sdram_we_n(SDRAM_WE_N),
		.sdram_clk_clk(SDRAM_CLK),
		.i2c_serial_sda_in(I2C_SDA_IN),
		.i2c_serial_scl_in(I2C_SCL_IN),
		.i2c_serial_sda_oe(I2C_SDA_OE),
		.i2c_serial_scl_oe(I2C_SCL_OE));
endmodule
