module final_project (CLOCK_50, KEY, SW, LEDR, LEDG, HEX0, HEX1, SDRAM_ADDR, SDRAM_BA, SDRAM_CAS_N, 
							SDRAM_CKE, SDRAM_CS_N, SDRAM_DQ, SDRAM_DQM, SDRAM_RAS_N, SDRAM_WE_N, SDRAM_CLK,
							BME_CSN, BME_IRQ, BME_MISO, BME_MOSI, BME_SCK, 
							NRF_CE, NRF_CSN, NRF_IRQ, NRF_MISO, NRF_MOSI, NRF_SCK
							);
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
	
	output BME_CSN;
	input BME_IRQ;
	output BME_MOSI;
	output BME_SCK;
	input BME_MISO;
	
	output		  NRF_CE;
	output		  NRF_CSN;
	input			  NRF_IRQ;
	input			  NRF_MISO;
	output		  NRF_MOSI;
	output		  NRF_SCK;
	
	

	
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
		.bme_csn_export(BME_CSN),
		.bme_irq_export(BME_IRQ),
		.bme_miso_export(BME_MISO),
		.bme_mosi_export(BME_MOSI),
		.bme_sck_export(BME_SCK),
		.nrf_ce_export(NRF_CE),
		.nrf_csn_export(NRF_CSN),
		.nrf_irq_export(NRF_IRQ),
		.nrf_miso_export(NRF_MISO),
		.nrf_mosi_export(NRF_MOSI),
		.nrf_sck_export(NRF_SCK),
	);
endmodule
