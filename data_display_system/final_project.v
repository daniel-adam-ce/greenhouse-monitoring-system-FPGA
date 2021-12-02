module final_project (CLOCK_50, KEY, SW, LEDR, LEDG, HEX0, HEX1, SDRAM_ADDR, SDRAM_BA, SDRAM_CAS_N, 
							SDRAM_CKE, SDRAM_CS_N, SDRAM_DQ, SDRAM_DQM, SDRAM_RAS_N, SDRAM_WE_N, SDRAM_CLK,
							NRF_CE, NRF_CSN, NRF_IRQ, NRF_MISO, NRF_MOSI, NRF_SCK, /*LCD_RS, LCD_RW, LCD_DATA, 
							LCD_E, LCD_ON*/);

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
	output		  NRF_CE;
	output		  NRF_CSN;
	input			  NRF_IRQ;
	input			  NRF_MISO;
	output		  NRF_MOSI;
	output		  NRF_SCK;
	//output		  LCD_RS;
	//output		  LCD_RW;
	//inout	 [7:0]  LCD_DATA;
	//output		  LCD_E;
	//output		  LCD_ON;
	
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
		.nrf_ce_export(NRF_CE),
		.nrf_csn_export(NRF_CSN),
		.nrf_irq_export(NRF_IRQ),
		.nrf_miso_export(NRF_MISO),
		.nrf_mosi_export(NRF_MOSI),
		.nrf_sck_export(NRF_SCK),
		/*.character_lcd_DATA(LCD_DATA),
		.character_lcd_ON(LCD_ON),
		.character_lcd_BLON(),
		.character_lcd_EN(LCD_EN),
		.character_lcd_RS(LCD_RS),
		.character_lcd_RW(LCD_RW)*/);

endmodule
