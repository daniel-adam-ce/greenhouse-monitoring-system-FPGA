	nios_system u0 (
		.clk_clk            (<connected-to-clk_clk>),            //         clk.clk
		.i2c_serial_sda_in  (<connected-to-i2c_serial_sda_in>),  //  i2c_serial.sda_in
		.i2c_serial_scl_in  (<connected-to-i2c_serial_scl_in>),  //            .scl_in
		.i2c_serial_sda_oe  (<connected-to-i2c_serial_sda_oe>),  //            .sda_oe
		.i2c_serial_scl_oe  (<connected-to-i2c_serial_scl_oe>),  //            .scl_oe
		.keys_export        (<connected-to-keys_export>),        //        keys.export
		.leds_g_export      (<connected-to-leds_g_export>),      //      leds_g.export
		.leds_r_export      (<connected-to-leds_r_export>),      //      leds_r.export
		.reset_reset        (<connected-to-reset_reset>),        //       reset.reset
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

