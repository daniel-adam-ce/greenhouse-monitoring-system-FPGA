	nios_system u0 (
		.clk_clk            (<connected-to-clk_clk>),            //         clk.clk
		.keys_export        (<connected-to-keys_export>),        //        keys.export
		.lcd_DATA           (<connected-to-lcd_DATA>),           //         lcd.DATA
		.lcd_ON             (<connected-to-lcd_ON>),             //            .ON
		.lcd_BLON           (<connected-to-lcd_BLON>),           //            .BLON
		.lcd_EN             (<connected-to-lcd_EN>),             //            .EN
		.lcd_RS             (<connected-to-lcd_RS>),             //            .RS
		.lcd_RW             (<connected-to-lcd_RW>),             //            .RW
		.leds_g_export      (<connected-to-leds_g_export>),      //      leds_g.export
		.leds_r_export      (<connected-to-leds_r_export>),      //      leds_r.export
		.nrf_ce_export      (<connected-to-nrf_ce_export>),      //      nrf_ce.export
		.nrf_csn_export     (<connected-to-nrf_csn_export>),     //     nrf_csn.export
		.nrf_irq_export     (<connected-to-nrf_irq_export>),     //     nrf_irq.export
		.nrf_miso_export    (<connected-to-nrf_miso_export>),    //    nrf_miso.export
		.nrf_mosi_export    (<connected-to-nrf_mosi_export>),    //    nrf_mosi.export
		.nrf_sck_export     (<connected-to-nrf_sck_export>),     //     nrf_sck.export
		.reset_reset        (<connected-to-reset_reset>),        //       reset.reset
		.sd_card_b_SD_cmd   (<connected-to-sd_card_b_SD_cmd>),   //     sd_card.b_SD_cmd
		.sd_card_b_SD_dat   (<connected-to-sd_card_b_SD_dat>),   //            .b_SD_dat
		.sd_card_b_SD_dat3  (<connected-to-sd_card_b_SD_dat3>),  //            .b_SD_dat3
		.sd_card_o_SD_clock (<connected-to-sd_card_o_SD_clock>), //            .o_SD_clock
		.sdram_addr         (<connected-to-sdram_addr>),         //       sdram.addr
		.sdram_ba           (<connected-to-sdram_ba>),           //            .ba
		.sdram_cas_n        (<connected-to-sdram_cas_n>),        //            .cas_n
		.sdram_cke          (<connected-to-sdram_cke>),          //            .cke
		.sdram_cs_n         (<connected-to-sdram_cs_n>),         //            .cs_n
		.sdram_dq           (<connected-to-sdram_dq>),           //            .dq
		.sdram_dqm          (<connected-to-sdram_dqm>),          //            .dqm
		.sdram_ras_n        (<connected-to-sdram_ras_n>),        //            .ras_n
		.sdram_we_n         (<connected-to-sdram_we_n>),         //            .we_n
		.sdram_clk_clk      (<connected-to-sdram_clk_clk>),      //   sdram_clk.clk
		.seven_seg_0_export (<connected-to-seven_seg_0_export>), // seven_seg_0.export
		.seven_seg_1_export (<connected-to-seven_seg_1_export>), // seven_seg_1.export
		.switches_export    (<connected-to-switches_export>)     //    switches.export
	);

