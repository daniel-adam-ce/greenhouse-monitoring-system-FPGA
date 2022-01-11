
module nios_system (
	clk_clk,
	keys_export,
	lcd_DATA,
	lcd_ON,
	lcd_BLON,
	lcd_EN,
	lcd_RS,
	lcd_RW,
	leds_g_export,
	leds_r_export,
	nrf_ce_export,
	nrf_csn_export,
	nrf_irq_export,
	nrf_miso_export,
	nrf_mosi_export,
	nrf_sck_export,
	reset_reset,
	sd_card_b_SD_cmd,
	sd_card_b_SD_dat,
	sd_card_b_SD_dat3,
	sd_card_o_SD_clock,
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
	switches_export);	

	input		clk_clk;
	input	[3:0]	keys_export;
	inout	[7:0]	lcd_DATA;
	output		lcd_ON;
	output		lcd_BLON;
	output		lcd_EN;
	output		lcd_RS;
	output		lcd_RW;
	output	[7:0]	leds_g_export;
	output	[31:0]	leds_r_export;
	output		nrf_ce_export;
	output		nrf_csn_export;
	input		nrf_irq_export;
	input		nrf_miso_export;
	output		nrf_mosi_export;
	output		nrf_sck_export;
	input		reset_reset;
	inout		sd_card_b_SD_cmd;
	inout		sd_card_b_SD_dat;
	inout		sd_card_b_SD_dat3;
	output		sd_card_o_SD_clock;
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
endmodule
