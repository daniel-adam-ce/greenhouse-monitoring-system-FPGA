
module nios_system (
	bme_csn_export,
	bme_irq_export,
	bme_miso_export,
	bme_mosi_export,
	bme_sck_export,
	clk_clk,
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
	nrf_csn_export,
	nrf_sck_export,
	nrf_mosi_export,
	nrf_miso_export,
	nrf_ce_export,
	nrf_irq_export);	

	output		bme_csn_export;
	input		bme_irq_export;
	input		bme_miso_export;
	output		bme_mosi_export;
	output		bme_sck_export;
	input		clk_clk;
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
	output		nrf_csn_export;
	output		nrf_sck_export;
	output		nrf_mosi_export;
	input		nrf_miso_export;
	output		nrf_ce_export;
	input		nrf_irq_export;
endmodule
