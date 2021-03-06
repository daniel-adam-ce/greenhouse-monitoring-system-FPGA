/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'nios_system'
 * SOPC Builder design path: ../../nios_system.sopcinfo
 *
 * Generated: Sun Dec 05 14:13:33 PST 2021
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00001820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1c
#define ALT_CPU_DCACHE_BYPASS_MASK 0x80000000
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x08000020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_NAME "nios2_gen2_0"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x08000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00001820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1c
#define NIOS2_DCACHE_BYPASS_MASK 0x80000000
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x08000020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x08000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2
#define __ALTERA_UP_AVALON_CHARACTER_LCD
#define __ALTERA_UP_SD_CARD_AVALON_INTERFACE


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x24e8
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x24e8
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x24e8
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_system"


/*
 * character_lcd configuration
 *
 */

#define ALT_MODULE_CLASS_character_lcd altera_up_avalon_character_lcd
#define CHARACTER_LCD_BASE 0x24f0
#define CHARACTER_LCD_IRQ -1
#define CHARACTER_LCD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHARACTER_LCD_NAME "/dev/character_lcd"
#define CHARACTER_LCD_SPAN 2
#define CHARACTER_LCD_TYPE "altera_up_avalon_character_lcd"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_0
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x24e8
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * keys configuration
 *
 */

#define ALT_MODULE_CLASS_keys altera_avalon_pio
#define KEYS_BASE 0x2490
#define KEYS_BIT_CLEARING_EDGE_REGISTER 0
#define KEYS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEYS_CAPTURE 1
#define KEYS_DATA_WIDTH 4
#define KEYS_DO_TEST_BENCH_WIRING 0
#define KEYS_DRIVEN_SIM_VALUE 0
#define KEYS_EDGE_TYPE "FALLING"
#define KEYS_FREQ 50000000
#define KEYS_HAS_IN 1
#define KEYS_HAS_OUT 0
#define KEYS_HAS_TRI 0
#define KEYS_IRQ 2
#define KEYS_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEYS_IRQ_TYPE "EDGE"
#define KEYS_NAME "/dev/keys"
#define KEYS_RESET_VALUE 0
#define KEYS_SPAN 16
#define KEYS_TYPE "altera_avalon_pio"


/*
 * leds_g configuration
 *
 */

#define ALT_MODULE_CLASS_leds_g altera_avalon_pio
#define LEDS_G_BASE 0x2480
#define LEDS_G_BIT_CLEARING_EDGE_REGISTER 0
#define LEDS_G_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDS_G_CAPTURE 0
#define LEDS_G_DATA_WIDTH 8
#define LEDS_G_DO_TEST_BENCH_WIRING 0
#define LEDS_G_DRIVEN_SIM_VALUE 0
#define LEDS_G_EDGE_TYPE "NONE"
#define LEDS_G_FREQ 50000000
#define LEDS_G_HAS_IN 0
#define LEDS_G_HAS_OUT 1
#define LEDS_G_HAS_TRI 0
#define LEDS_G_IRQ -1
#define LEDS_G_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDS_G_IRQ_TYPE "NONE"
#define LEDS_G_NAME "/dev/leds_g"
#define LEDS_G_RESET_VALUE 0
#define LEDS_G_SPAN 16
#define LEDS_G_TYPE "altera_avalon_pio"


/*
 * leds_r configuration
 *
 */

#define ALT_MODULE_CLASS_leds_r altera_avalon_pio
#define LEDS_R_BASE 0x24c0
#define LEDS_R_BIT_CLEARING_EDGE_REGISTER 0
#define LEDS_R_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDS_R_CAPTURE 0
#define LEDS_R_DATA_WIDTH 32
#define LEDS_R_DO_TEST_BENCH_WIRING 0
#define LEDS_R_DRIVEN_SIM_VALUE 0
#define LEDS_R_EDGE_TYPE "NONE"
#define LEDS_R_FREQ 50000000
#define LEDS_R_HAS_IN 0
#define LEDS_R_HAS_OUT 1
#define LEDS_R_HAS_TRI 0
#define LEDS_R_IRQ -1
#define LEDS_R_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDS_R_IRQ_TYPE "NONE"
#define LEDS_R_NAME "/dev/leds_r"
#define LEDS_R_RESET_VALUE 0
#define LEDS_R_SPAN 16
#define LEDS_R_TYPE "altera_avalon_pio"


/*
 * new_sdram_controller_0 configuration
 *
 */

#define ALT_MODULE_CLASS_new_sdram_controller_0 altera_avalon_new_sdram_controller
#define NEW_SDRAM_CONTROLLER_0_BASE 0x8000000
#define NEW_SDRAM_CONTROLLER_0_CAS_LATENCY 3
#define NEW_SDRAM_CONTROLLER_0_CONTENTS_INFO
#define NEW_SDRAM_CONTROLLER_0_INIT_NOP_DELAY 0.0
#define NEW_SDRAM_CONTROLLER_0_INIT_REFRESH_COMMANDS 2
#define NEW_SDRAM_CONTROLLER_0_IRQ -1
#define NEW_SDRAM_CONTROLLER_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NEW_SDRAM_CONTROLLER_0_IS_INITIALIZED 1
#define NEW_SDRAM_CONTROLLER_0_NAME "/dev/new_sdram_controller_0"
#define NEW_SDRAM_CONTROLLER_0_POWERUP_DELAY 100.0
#define NEW_SDRAM_CONTROLLER_0_REFRESH_PERIOD 15.625
#define NEW_SDRAM_CONTROLLER_0_REGISTER_DATA_IN 1
#define NEW_SDRAM_CONTROLLER_0_SDRAM_ADDR_WIDTH 0x16
#define NEW_SDRAM_CONTROLLER_0_SDRAM_BANK_WIDTH 2
#define NEW_SDRAM_CONTROLLER_0_SDRAM_COL_WIDTH 8
#define NEW_SDRAM_CONTROLLER_0_SDRAM_DATA_WIDTH 32
#define NEW_SDRAM_CONTROLLER_0_SDRAM_NUM_BANKS 4
#define NEW_SDRAM_CONTROLLER_0_SDRAM_NUM_CHIPSELECTS 1
#define NEW_SDRAM_CONTROLLER_0_SDRAM_ROW_WIDTH 12
#define NEW_SDRAM_CONTROLLER_0_SHARED_DATA 0
#define NEW_SDRAM_CONTROLLER_0_SIM_MODEL_BASE 0
#define NEW_SDRAM_CONTROLLER_0_SPAN 16777216
#define NEW_SDRAM_CONTROLLER_0_STARVATION_INDICATOR 0
#define NEW_SDRAM_CONTROLLER_0_TRISTATE_BRIDGE_SLAVE ""
#define NEW_SDRAM_CONTROLLER_0_TYPE "altera_avalon_new_sdram_controller"
#define NEW_SDRAM_CONTROLLER_0_T_AC 5.5
#define NEW_SDRAM_CONTROLLER_0_T_MRD 3
#define NEW_SDRAM_CONTROLLER_0_T_RCD 20.0
#define NEW_SDRAM_CONTROLLER_0_T_RFC 70.0
#define NEW_SDRAM_CONTROLLER_0_T_RP 20.0
#define NEW_SDRAM_CONTROLLER_0_T_WR 14.0


/*
 * nrf_ce configuration
 *
 */

#define ALT_MODULE_CLASS_nrf_ce altera_avalon_pio
#define NRF_CE_BASE 0x2420
#define NRF_CE_BIT_CLEARING_EDGE_REGISTER 0
#define NRF_CE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NRF_CE_CAPTURE 0
#define NRF_CE_DATA_WIDTH 1
#define NRF_CE_DO_TEST_BENCH_WIRING 0
#define NRF_CE_DRIVEN_SIM_VALUE 0
#define NRF_CE_EDGE_TYPE "NONE"
#define NRF_CE_FREQ 50000000
#define NRF_CE_HAS_IN 0
#define NRF_CE_HAS_OUT 1
#define NRF_CE_HAS_TRI 0
#define NRF_CE_IRQ -1
#define NRF_CE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NRF_CE_IRQ_TYPE "NONE"
#define NRF_CE_NAME "/dev/nrf_ce"
#define NRF_CE_RESET_VALUE 0
#define NRF_CE_SPAN 16
#define NRF_CE_TYPE "altera_avalon_pio"


/*
 * nrf_csn configuration
 *
 */

#define ALT_MODULE_CLASS_nrf_csn altera_avalon_pio
#define NRF_CSN_BASE 0x2470
#define NRF_CSN_BIT_CLEARING_EDGE_REGISTER 0
#define NRF_CSN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NRF_CSN_CAPTURE 0
#define NRF_CSN_DATA_WIDTH 1
#define NRF_CSN_DO_TEST_BENCH_WIRING 0
#define NRF_CSN_DRIVEN_SIM_VALUE 0
#define NRF_CSN_EDGE_TYPE "NONE"
#define NRF_CSN_FREQ 50000000
#define NRF_CSN_HAS_IN 0
#define NRF_CSN_HAS_OUT 1
#define NRF_CSN_HAS_TRI 0
#define NRF_CSN_IRQ -1
#define NRF_CSN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NRF_CSN_IRQ_TYPE "NONE"
#define NRF_CSN_NAME "/dev/nrf_csn"
#define NRF_CSN_RESET_VALUE 0
#define NRF_CSN_SPAN 16
#define NRF_CSN_TYPE "altera_avalon_pio"


/*
 * nrf_irq configuration
 *
 */

#define ALT_MODULE_CLASS_nrf_irq altera_avalon_pio
#define NRF_IRQ_BASE 0x2430
#define NRF_IRQ_BIT_CLEARING_EDGE_REGISTER 0
#define NRF_IRQ_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NRF_IRQ_CAPTURE 1
#define NRF_IRQ_DATA_WIDTH 1
#define NRF_IRQ_DO_TEST_BENCH_WIRING 0
#define NRF_IRQ_DRIVEN_SIM_VALUE 0
#define NRF_IRQ_EDGE_TYPE "FALLING"
#define NRF_IRQ_FREQ 50000000
#define NRF_IRQ_HAS_IN 1
#define NRF_IRQ_HAS_OUT 0
#define NRF_IRQ_HAS_TRI 0
#define NRF_IRQ_IRQ 3
#define NRF_IRQ_IRQ_INTERRUPT_CONTROLLER_ID 0
#define NRF_IRQ_IRQ_TYPE "EDGE"
#define NRF_IRQ_NAME "/dev/nrf_irq"
#define NRF_IRQ_RESET_VALUE 0
#define NRF_IRQ_SPAN 16
#define NRF_IRQ_TYPE "altera_avalon_pio"


/*
 * nrf_miso configuration
 *
 */

#define ALT_MODULE_CLASS_nrf_miso altera_avalon_pio
#define NRF_MISO_BASE 0x2440
#define NRF_MISO_BIT_CLEARING_EDGE_REGISTER 0
#define NRF_MISO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NRF_MISO_CAPTURE 0
#define NRF_MISO_DATA_WIDTH 1
#define NRF_MISO_DO_TEST_BENCH_WIRING 0
#define NRF_MISO_DRIVEN_SIM_VALUE 0
#define NRF_MISO_EDGE_TYPE "NONE"
#define NRF_MISO_FREQ 50000000
#define NRF_MISO_HAS_IN 1
#define NRF_MISO_HAS_OUT 0
#define NRF_MISO_HAS_TRI 0
#define NRF_MISO_IRQ -1
#define NRF_MISO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NRF_MISO_IRQ_TYPE "NONE"
#define NRF_MISO_NAME "/dev/nrf_miso"
#define NRF_MISO_RESET_VALUE 0
#define NRF_MISO_SPAN 16
#define NRF_MISO_TYPE "altera_avalon_pio"


/*
 * nrf_mosi configuration
 *
 */

#define ALT_MODULE_CLASS_nrf_mosi altera_avalon_pio
#define NRF_MOSI_BASE 0x2450
#define NRF_MOSI_BIT_CLEARING_EDGE_REGISTER 0
#define NRF_MOSI_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NRF_MOSI_CAPTURE 0
#define NRF_MOSI_DATA_WIDTH 1
#define NRF_MOSI_DO_TEST_BENCH_WIRING 0
#define NRF_MOSI_DRIVEN_SIM_VALUE 0
#define NRF_MOSI_EDGE_TYPE "NONE"
#define NRF_MOSI_FREQ 50000000
#define NRF_MOSI_HAS_IN 0
#define NRF_MOSI_HAS_OUT 1
#define NRF_MOSI_HAS_TRI 0
#define NRF_MOSI_IRQ -1
#define NRF_MOSI_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NRF_MOSI_IRQ_TYPE "NONE"
#define NRF_MOSI_NAME "/dev/nrf_mosi"
#define NRF_MOSI_RESET_VALUE 0
#define NRF_MOSI_SPAN 16
#define NRF_MOSI_TYPE "altera_avalon_pio"


/*
 * nrf_sck configuration
 *
 */

#define ALT_MODULE_CLASS_nrf_sck altera_avalon_pio
#define NRF_SCK_BASE 0x2460
#define NRF_SCK_BIT_CLEARING_EDGE_REGISTER 0
#define NRF_SCK_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NRF_SCK_CAPTURE 0
#define NRF_SCK_DATA_WIDTH 1
#define NRF_SCK_DO_TEST_BENCH_WIRING 0
#define NRF_SCK_DRIVEN_SIM_VALUE 0
#define NRF_SCK_EDGE_TYPE "NONE"
#define NRF_SCK_FREQ 50000000
#define NRF_SCK_HAS_IN 0
#define NRF_SCK_HAS_OUT 1
#define NRF_SCK_HAS_TRI 0
#define NRF_SCK_IRQ -1
#define NRF_SCK_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NRF_SCK_IRQ_TYPE "NONE"
#define NRF_SCK_NAME "/dev/nrf_sck"
#define NRF_SCK_RESET_VALUE 0
#define NRF_SCK_SPAN 16
#define NRF_SCK_TYPE "altera_avalon_pio"


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x0
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "nios_system_onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 4096
#define ONCHIP_MEMORY2_0_SPAN 4096
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * sd_card_interface configuration
 *
 */

#define ALT_MODULE_CLASS_sd_card_interface Altera_UP_SD_Card_Avalon_Interface
#define SD_CARD_INTERFACE_BASE 0x2000
#define SD_CARD_INTERFACE_IRQ -1
#define SD_CARD_INTERFACE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SD_CARD_INTERFACE_NAME "/dev/sd_card_interface"
#define SD_CARD_INTERFACE_SPAN 1024
#define SD_CARD_INTERFACE_TYPE "Altera_UP_SD_Card_Avalon_Interface"


/*
 * seven_seg_0 configuration
 *
 */

#define ALT_MODULE_CLASS_seven_seg_0 altera_avalon_pio
#define SEVEN_SEG_0_BASE 0x24b0
#define SEVEN_SEG_0_BIT_CLEARING_EDGE_REGISTER 0
#define SEVEN_SEG_0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEVEN_SEG_0_CAPTURE 0
#define SEVEN_SEG_0_DATA_WIDTH 32
#define SEVEN_SEG_0_DO_TEST_BENCH_WIRING 0
#define SEVEN_SEG_0_DRIVEN_SIM_VALUE 0
#define SEVEN_SEG_0_EDGE_TYPE "NONE"
#define SEVEN_SEG_0_FREQ 50000000
#define SEVEN_SEG_0_HAS_IN 0
#define SEVEN_SEG_0_HAS_OUT 1
#define SEVEN_SEG_0_HAS_TRI 0
#define SEVEN_SEG_0_IRQ -1
#define SEVEN_SEG_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEVEN_SEG_0_IRQ_TYPE "NONE"
#define SEVEN_SEG_0_NAME "/dev/seven_seg_0"
#define SEVEN_SEG_0_RESET_VALUE 0
#define SEVEN_SEG_0_SPAN 16
#define SEVEN_SEG_0_TYPE "altera_avalon_pio"


/*
 * seven_seg_1 configuration
 *
 */

#define ALT_MODULE_CLASS_seven_seg_1 altera_avalon_pio
#define SEVEN_SEG_1_BASE 0x24a0
#define SEVEN_SEG_1_BIT_CLEARING_EDGE_REGISTER 0
#define SEVEN_SEG_1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEVEN_SEG_1_CAPTURE 0
#define SEVEN_SEG_1_DATA_WIDTH 32
#define SEVEN_SEG_1_DO_TEST_BENCH_WIRING 0
#define SEVEN_SEG_1_DRIVEN_SIM_VALUE 0
#define SEVEN_SEG_1_EDGE_TYPE "NONE"
#define SEVEN_SEG_1_FREQ 50000000
#define SEVEN_SEG_1_HAS_IN 0
#define SEVEN_SEG_1_HAS_OUT 1
#define SEVEN_SEG_1_HAS_TRI 0
#define SEVEN_SEG_1_IRQ -1
#define SEVEN_SEG_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEVEN_SEG_1_IRQ_TYPE "NONE"
#define SEVEN_SEG_1_NAME "/dev/seven_seg_1"
#define SEVEN_SEG_1_RESET_VALUE 0
#define SEVEN_SEG_1_SPAN 16
#define SEVEN_SEG_1_TYPE "altera_avalon_pio"


/*
 * switches configuration
 *
 */

#define ALT_MODULE_CLASS_switches altera_avalon_pio
#define SWITCHES_BASE 0x24d0
#define SWITCHES_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCHES_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCHES_CAPTURE 0
#define SWITCHES_DATA_WIDTH 32
#define SWITCHES_DO_TEST_BENCH_WIRING 0
#define SWITCHES_DRIVEN_SIM_VALUE 0
#define SWITCHES_EDGE_TYPE "NONE"
#define SWITCHES_FREQ 50000000
#define SWITCHES_HAS_IN 1
#define SWITCHES_HAS_OUT 0
#define SWITCHES_HAS_TRI 0
#define SWITCHES_IRQ -1
#define SWITCHES_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SWITCHES_IRQ_TYPE "NONE"
#define SWITCHES_NAME "/dev/switches"
#define SWITCHES_RESET_VALUE 0
#define SWITCHES_SPAN 16
#define SWITCHES_TYPE "altera_avalon_pio"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x24e0
#define SYSID_QSYS_0_ID 0
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1638742043
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x2400
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 50000000
#define TIMER_0_IRQ 1
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 49999
#define TIMER_0_MULT 0.001
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
