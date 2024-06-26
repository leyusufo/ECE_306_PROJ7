//------------------------------------------------------------------------------
//
//  Description: This file contains several macro definitions for por pins
//
//
//  Loyda Yusufova
//  Febreuary 12
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.20.1)
//------------------------------------------------------------------------------

//port1 pins
#define RED_LED (0x01)          // 0 RED LED 0
#define A1_SEEED (0x02)          // 1 A1_SEEED
#define V_DETECT_L (0x04)       // 2 V_DETECT_L
#define V_DETECT_R (0x08)        // 3 V_DETECT_R
#define A4_SEEED (0x10)         // 4 A4_SEEED
#define V_THUMB (0x20)          // 5 V_THUMB
#define UCA0RXD (0x40)          // 6 Back Channel UCA0RXD
#define UCA0TXD (0x80)          // 7 Back Channel UCA0TXD

//port2 pins
#define P2_0 (0x01)             // 0
#define IR_LED (0x02)           // 1 IR LED on/off signal
#define P2_2 (0x04)             // 2
#define SW2 (0x08)              // 3 SW2
#define IOT_PROG_SEL (0x10)     // 4 IOT_PROG_SEL
#define P2_5 (0x20)             // 5
#define LFXOUT (0x40)           // 6 XOUTR
#define LFXIN (0x80)            // 7 XIN

//port3 pins
#define TEST_PROBE (0x01)       // 0 TEST PROBE
#define OPT_INT (0x02)          // 1 OPT_INT
#define OA2N (0x04)             // 2 Photodiode Circuit
#define OA2P (0x08)             // 3 Photodiode Circuit
#define SMCLK_OUT (0x10)        // 4 SMCLK
#define DAC_CNTL (0x20)         // 5 DAC signal from Processor
#define IOT_LINK (0x40)         // 6 IOT_LINK
#define IOT_RESET (0x80)        // 7 IOT_RESET

// Port4 Pins
#define RESET_LCD (0x01)        // 0 LCD Reset
#define SW1 (0x02)              // 1 SW1
#define UCA1RXD (0x04)          // 2 Back Channel UCA1RXD
#define UCA1TXD (0x08)          // 3 Back Channel UCA1TXD
#define UCB1_CS_LCD (0x10)      // 4 Chip Select
#define UCB1CLK (0x20)          // 5 SPI mode - clock output�UCB1CLK
#define UCB1SIMO (0x40)         // 6 UCB1SIMO
#define UCB1SOMI (0x80)         // 7 UCB1SOMI

//port5 pins
#define CHECK_BAT (0x01)
#define V_BAT (0x02)
#define V_DAC (0x04)
#define V_3_3 (0x08)
#define IOT_PROG_MODE (0x10)

//ports6 pins
#define R_FORWARD (0x01)
#define L_FORWARD (0x02)
#define R_REVERSE (0x04)
#define L_REVERSE (0x08)
#define LCD_BACKLITE (0x10)
#define P6_5 (0x20)
#define GRN_LED (0x40)
//------------------------------------------------------------------------------