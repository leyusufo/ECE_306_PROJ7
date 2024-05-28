//------------------------------------------------------------------------------
//
//  Description: This file contains several macro definitions that can be used
//               in other files
//
//
//  Loyda Yusufova
//  Febreuary 12
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.20.1)
//------------------------------------------------------------------------------
#include "ports.h"

//General Macros
//------------------------------------------------------------------------------
#define ALWAYS                  (1)
#define RESET_STATE             (0)
#define  TRUE                   (1)
#define FALSE                   (0)
//------------------------------------------------------------------------------

// MACROS used in clocks.c
//------------------------------------------------------------------------------
#define MCLK_FREQ_MHZ 8                     // MCLK = 8MHz
#define CLEAR_REGISTER     (0X0000)
//------------------------------------------------------------------------------

//macros for switches
#define DEBOUNCE_TIME (20)
#define DEBOUNCE_RESTART (0)
#define PRESSED (0)
#define RELEASED (1)

//macro for Peripheral 4 
#define P4PUD (P4OUT)           //pull up/down resistor

//macros for timerB0
#define TB0CCR0_INTERVAL (6250)       //50ms-for a 1s timer-display + time-sequence
#define TB0CCR1_INTERVAL (50000)       //400ms- for a second timer-switch 1
#define TB0CCR2_INTERVAL (50000)       //400ms-for a second timer-switch 2
#define FIFTY_MS_COUNT 10               //for ccr0 backlite count

//macros for timerB1
#define TB1CCR0_INTERVAL (62500)       //500ms-start the wheels
#define TB1CCR1_INTERVAL (3125)       //30ms-ADC readings
#define TB1CCR2_INTERVAL (62500)       //find the black line

//macros for timerB2
#define TB2CCR0_INTERVAL (512)       //
#define TB2CCR1_INTERVAL (512)       //
#define TB2CCR2_INTERVAL (512)       //

//macros for timerB3:movement of the motors
#define RIGHT_FORWARD_SPEED (TB3CCR1)
#define RIGHT_FORWARD_PWM (10010)
#define RIGHT_FORWARD_PWM_MEDIUM (8020)
#define RIGHT_FORWARD_PWM_LOW (6500)
#define RIGHT_FORWARD_PWM_LOWEST (5600)
#define LEFT_FORWARD_SPEED (TB3CCR2)
#define LEFT_FORWARD_PWM (10000)
#define LEFT_FORWARD_PWM_MEDIUM (8000)
#define LEFT_FORWARD_PWM_LOW (6500)
#define LEFT_FORWARD_PWM_LOWEST (5600)
#define RIGHT_REVERSE_SPEED (TB3CCR3)
#define RIGHT_REVERSE_PWM (6000)
#define LEFT_REVERSE_SPEED (TB3CCR4)
#define LEFT_REVERSE_PWM (6000)
#define WHEEL_OFF (0)
#define WHEEL_PERIOD (50000)

// Main While loop switch cases
#define Time_Sequence_Rate (50) // 50 millisecods
#define TS_1250 (1250/Time_Sequence_Rate) // 1.25 seconds
#define TS_1000 (1000/Time_Sequence_Rate) // 1 second
#define TS_750 (750/Time_Sequence_Rate) // 0.75 seconds
#define TS_500 (500/Time_Sequence_Rate) // 0.50 seconds
#define TS_250 (250/Time_Sequence_Rate) // 0.25 seconds

//macros for adc
#define SAMPLE_SIZE (8)
#define THOUSANDS (1000)
#define HUNDREDS (100)
#define TENS (10)
#define ONES (1)
#define ZERO_ASCII (0x30)
#define BEGIN (600)

//DAC
#define INITIAL_VAL_DAC (4000)
#define FINAL_VAL_DAC (1200)

