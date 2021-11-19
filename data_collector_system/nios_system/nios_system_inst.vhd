	component nios_system is
		port (
			clk_clk            : in    std_logic                     := 'X';             -- clk
			i2c_serial_sda_in  : in    std_logic                     := 'X';             -- sda_in
			i2c_serial_scl_in  : in    std_logic                     := 'X';             -- scl_in
			i2c_serial_sda_oe  : out   std_logic;                                        -- sda_oe
			i2c_serial_scl_oe  : out   std_logic;                                        -- scl_oe
			keys_export        : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			leds_g_export      : out   std_logic_vector(7 downto 0);                     -- export
			leds_r_export      : out   std_logic_vector(31 downto 0);                    -- export
			reset_reset        : in    std_logic                     := 'X';             -- reset
			sdram_addr         : out   std_logic_vector(11 downto 0);                    -- addr
			sdram_ba           : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_cas_n        : out   std_logic;                                        -- cas_n
			sdram_cke          : out   std_logic;                                        -- cke
			sdram_cs_n         : out   std_logic;                                        -- cs_n
			sdram_dq           : inout std_logic_vector(31 downto 0) := (others => 'X'); -- dq
			sdram_dqm          : out   std_logic_vector(3 downto 0);                     -- dqm
			sdram_ras_n        : out   std_logic;                                        -- ras_n
			sdram_we_n         : out   std_logic;                                        -- we_n
			sdram_clk_clk      : out   std_logic;                                        -- clk
			seven_seg_0_export : out   std_logic_vector(31 downto 0);                    -- export
			seven_seg_1_export : out   std_logic_vector(31 downto 0);                    -- export
			switches_export    : in    std_logic_vector(31 downto 0) := (others => 'X'); -- export
			spi_0_serial_MISO  : in    std_logic                     := 'X';             -- MISO
			spi_0_serial_MOSI  : out   std_logic;                                        -- MOSI
			spi_0_serial_SCLK  : out   std_logic;                                        -- SCLK
			spi_0_serial_SS_n  : out   std_logic                                         -- SS_n
		);
	end component nios_system;

	u0 : component nios_system
		port map (
			clk_clk            => CONNECTED_TO_clk_clk,            --          clk.clk
			i2c_serial_sda_in  => CONNECTED_TO_i2c_serial_sda_in,  --   i2c_serial.sda_in
			i2c_serial_scl_in  => CONNECTED_TO_i2c_serial_scl_in,  --             .scl_in
			i2c_serial_sda_oe  => CONNECTED_TO_i2c_serial_sda_oe,  --             .sda_oe
			i2c_serial_scl_oe  => CONNECTED_TO_i2c_serial_scl_oe,  --             .scl_oe
			keys_export        => CONNECTED_TO_keys_export,        --         keys.export
			leds_g_export      => CONNECTED_TO_leds_g_export,      --       leds_g.export
			leds_r_export      => CONNECTED_TO_leds_r_export,      --       leds_r.export
			reset_reset        => CONNECTED_TO_reset_reset,        --        reset.reset
			sdram_addr         => CONNECTED_TO_sdram_addr,         --        sdram.addr
			sdram_ba           => CONNECTED_TO_sdram_ba,           --             .ba
			sdram_cas_n        => CONNECTED_TO_sdram_cas_n,        --             .cas_n
			sdram_cke          => CONNECTED_TO_sdram_cke,          --             .cke
			sdram_cs_n         => CONNECTED_TO_sdram_cs_n,         --             .cs_n
			sdram_dq           => CONNECTED_TO_sdram_dq,           --             .dq
			sdram_dqm          => CONNECTED_TO_sdram_dqm,          --             .dqm
			sdram_ras_n        => CONNECTED_TO_sdram_ras_n,        --             .ras_n
			sdram_we_n         => CONNECTED_TO_sdram_we_n,         --             .we_n
			sdram_clk_clk      => CONNECTED_TO_sdram_clk_clk,      --    sdram_clk.clk
			seven_seg_0_export => CONNECTED_TO_seven_seg_0_export, --  seven_seg_0.export
			seven_seg_1_export => CONNECTED_TO_seven_seg_1_export, --  seven_seg_1.export
			switches_export    => CONNECTED_TO_switches_export,    --     switches.export
			spi_0_serial_MISO  => CONNECTED_TO_spi_0_serial_MISO,  -- spi_0_serial.MISO
			spi_0_serial_MOSI  => CONNECTED_TO_spi_0_serial_MOSI,  --             .MOSI
			spi_0_serial_SCLK  => CONNECTED_TO_spi_0_serial_SCLK,  --             .SCLK
			spi_0_serial_SS_n  => CONNECTED_TO_spi_0_serial_SS_n   --             .SS_n
		);

