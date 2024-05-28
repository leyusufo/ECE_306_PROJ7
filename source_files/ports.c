//------------------------------------------------------------------------------
//
//  Description: This file contains several functions, each initializing the pins 
//               of each port of the MSP430
//
//
//  Loyda Yusufova
//  Febreuary 12
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.20.1)
//------------------------------------------------------------------------------
#include  "functions.h"
#include  "msp430.h"
#include "ports.h"
#include "macros.h"

// function to call the individual port initializations?
//------------------------------------------------------------------------------
void Init_Ports(void){
  Init_Port1();               //initializing pins of port 1
  Init_Port2();               //initializing pins of port 2
  Init_Port3();               //initializing pins of port 3
  Init_Port4();               //initializing pins of port 4
  Init_Port5();               //initializing pins of port 5
  Init_Port6();               //initializing pins of port 6
}
//------------------------------------------------------------------------------
                                                   
//initializing the pins of port 1
void Init_Port1(void){ // Configure Port 1
    P1OUT = 0x00;               // P1 set Low
    P1DIR = 0x00;               // Set P1 direction to input

    //P1 PIN 0
    P1SEL0 &= ~RED_LED;         // RED_LED GPIO operation (set to 0)
    P1SEL1 &= ~RED_LED;         // RED_LED GPIO operation (set to 0)
    P1OUT &= ~RED_LED;          //Initial value = 0
    P1DIR |= RED_LED;           // Direction = OUTPUT

    //P1 PIN 1
    //P1SEL0 |= A1_SEEED;         // A1_SEEED function operation (set to 1)
    //P1SEL1 |= A1_SEEED;         // A1_SEEED function operation (set to 1)
    P1SELC = A1_SEEED;              //must set P1SELC to 1 to set the GPIO bits at the same time

    //P1 PIN 2
    //P1SEL0 |= V_DETECT_L;       // V_DETECT_L function operation (set to 1)
    //P1SEL1 |= V_DETECT_L;       // V_DETECT_L function operation (set to 1)
    P1SELC = V_DETECT_L;              //must set P1SELC to 1 to set the GPIO bits at the same time

    //P1 PIN 3
    //P1SEL0 |= V_DETECT_R;       // V_DETECT_R function operation (set to 1)
    //P1SEL1 |= V_DETECT_R;       // V_DETECT_R function operation (set to 1)
    P1SELC = V_DETECT_R;              //must set P1SELC to 1 to set the GPIO bits at the same time

    //P1PIN 4
    P1SEL0 &= ~A4_SEEED;         // A4_SEEED function operation (set to 0)
    P1SEL1 |= A4_SEEED;          // A4_SEEED function operation (set to 1)
    P1DIR |= A4_SEEED;           // Direction = OUTPUT
    //P1SELC = A4_SEEED;              //must set P1SELC to 1 to set the GPIO bits at the same time

    //P1 PIN 5
    //P1SEL0 |= V_THUMB;          // V_THUMB function operation (set to 1)
    //P1SEL1 |= V_THUMB;          // V_THUMB function operation (set to 1)
    P1SELC = V_THUMB;              //must set P1SELC to 1 to set the GPIO bits at the same time

    //P1 PIN 6
    P1SEL0 |= UCA0RXD;          // UCA0RXD function operation (set to 1)
    P1SEL1 &= ~UCA0RXD;         // UCA0RXD function operation (set to 0)

    //P1 PIN 7
    P1SEL0 |= UCA0TXD;          // UCA0TXD function operation (set to 1)
    P1SEL1 &= UCA0TXD;          // UCA0TXD function operation (set to 0)
}

//initializing the pins of port 2
void Init_Port2(void){          // Configure Port 2
    P2OUT = 0x00;               // P2 set Low
    P2DIR = 0x00;               // Set P2 direction to input

    //P2 PIN 0
    P2SEL0 &= ~P2_0;            // P2_0 GPIO operation (set to 0)
    P2SEL1 &= ~P2_0;            // P2_0 GPIO operation (set to 0)
    P2DIR &= ~P2_0;             // Direction = input

    //P2 PIN 1
    P2SEL0 &= ~IR_LED;          // IR_LED GPIO operation (set to 0)
    P2SEL1 &= ~IR_LED;          // IR_LED GPIO operation (set to 0)
    P2OUT &= ~IR_LED;           // Initial Value = Low / Off
    P2DIR |= IR_LED;            // Direction = output

    //P2 PIN 2
    P2SEL0 &= ~P2_2;            // P2_2 GPIO operation (set to 0)
    P2SEL1 &= ~P2_2;            // P2_2 GPIO operation (set to 0)
    P2DIR &= ~P2_2;             // Direction = input

    //P2 PIN 3
    P2SEL0 &= ~SW2;             // SW2 Operation (set to 0)
    P2SEL1 &= ~SW2;             // SW2 Operation (set to 0)
    P2OUT |= SW2;               // Configure pullup resistor (set to 1)
    P2DIR &= ~SW2;              // Direction = input
    P2REN |= SW2;               // Enable pullup resistor
    P2IES |= SW2;               // P2.0 Hi/Lo edge interrupt
    P2IFG &= ~SW2;              // Clear all P2.6 interrupt flags
    P2IE |= SW2;                // P2.6 interrupt enabled

    //P2 PIN 4
    P2SEL0 &= ~IOT_PROG_SEL;    // IOT_PROG_SEL GPIO operation (set to 0)
    P2SEL1 &= ~IOT_PROG_SEL;    // IOT_PROG_SEL GPIO operation (set to 0)
    P2OUT &= ~IOT_PROG_SEL;     // Initial Value = Low / Off
    P2DIR |= IOT_PROG_SEL;      // Direction = output

    //P2 PIN 5
    P2SEL0 &= ~P2_5;            // P2_5 GPIO operation (set to 0)
    P2SEL1 &= ~P2_5;            // P2_5 GPIO operation (set to 0)
    P2DIR &= ~P2_5;             // Direction = input

    //P2 PIN 6
    P2SEL0 &= ~LFXOUT;          // LFXOUT Clock operation
    P2SEL1 |= LFXOUT;           // LFXOUT Clock operation

    //P2 PIN 7
    P2SEL0 &= ~LFXIN;           // LFXIN Clock operation
    P2SEL1 |= LFXIN;            // LFXIN Clock operation
}

//initializing the pins of port 3
void Init_Port3(void) {
    P3OUT = 0x00;               // p3 set Low
    P3DIR = 0x00;               // Set P3 direction to input

    // P3 PIN 0
    P3SEL0 &= ~TEST_PROBE;      // TEST_PROBE GPIO operation (set to 0)
    P3SEL1 &= ~TEST_PROBE;      // TEST_PROBE GPIO operation (set to 0)
    P3DIR &= ~TEST_PROBE;       //set TEST_PROBE direction to input

    //P3 PIN 1
    P3SEL0 &= ~OPT_INT;         // OPT_INT GPIO operation (set to 0)
    P3SEL1 &= ~OPT_INT;         // OPT_INT GPIO operation (set to 0)
    P3DIR &= ~OPT_INT;          //set OPT_INT direction to input

    //P3 PIN 2
    P3SEL0 |= OA2N;             // OA2N operation (set to 1)
    P3SEL1 |= OA2N;             // OA2N operation (set to 1)
    P3SELC = 0x04;              //Select bits cannot change to 1 at the same time
    P3DIR |= OA2N;              //set OPT_INT direction = output

    //P3 PIN 3
    P3SEL0 |= OA2P;             // OA2P operation (set to 1)
    P3SEL1 |= OA2P;             // OA2P operation (set to 1)
    P3SELC = 0x08;              //Select bits cannot change to 1 at the same time
    P3DIR |= OA2P;              //set OA2P direction to 1

    //P3 PIN 4
    P3SEL0 |= SMCLK_OUT;        // SMCLK_OUT operation (set to 1)
    P3SEL1 &= ~SMCLK_OUT;       // SMCLK_OUT operation (set to 0)
    P3DIR |= SMCLK_OUT;         //set SMCLK_OUT direction to output

    //P3 PIN 5
    P3SEL0 &= ~DAC_CNTL;        // DAC_CNTL GPIO operation (set to 0)
    P3SEL1 &= ~DAC_CNTL;        // DAC_CNTL GPIO operation (set to 0)
    P3OUT |= DAC_CNTL;          //output set high
    P3DIR |= DAC_CNTL;         //set DAC_CNTL direction to output

    //P3 PIN 6
    P3SEL0 &= ~IOT_LINK;        // IOT_LINK GPIO operation (set to 0)
    P3SEL1 &= ~IOT_LINK;        // IOT_LINK GPIO operation (set to 0)
    P3DIR &= ~IOT_LINK;         //set IOT_LINK direction to input

    //P3 PIN 7
    P3SEL0 &= ~IOT_RESET;       // IOT_RESET GPIO operation (set to 0)
    P3SEL1 &= ~IOT_RESET;       // IOT_RESET GPIO operation (set to 0)
    P3DIR &= ~IOT_RESET;        //set IOT_RESET direction to input
}

//initializing the pins of port 4
void Init_Port4(void){
    P4OUT = 0x00; // p4 set Low
    P4DIR = 0x00; // Set P4 direction to input

    // P4 PIN 0
    P4SEL0 &= ~RESET_LCD;       // RESET_LCD GPIO operation (set to 0)
    P4SEL1 &= ~RESET_LCD;       // RESET_LCD GPIO operation (set to 0)
    P4OUT &= ~RESET_LCD;        // Set RESET_LCD On [Low]
    P4DIR |= RESET_LCD;         // Set RESET_LCD direction to output

    // P4 PIN 1
    P4SEL0 &= ~SW1;             // SW1 GPIO operation (set to 0)
    P4SEL1 &= ~SW1;             // SW1 GPIO operation (set to 0)
    P4PUD |= SW1;               // Configure pullup resistor
    P4DIR &= ~SW1;              // Direction = input
    P4REN |= SW1;               // Enable pullup resistor
    P4IES |= SW1;               // P2.0 Hi/Lo edge interrupt
    P4IFG &= ~SW1;              // Clear all P2.6 interrupt flags
    P4IE |= SW1;                // P2.6 interrupt enabled

    // P4 PIN 2
    P4SEL0 |= UCA1TXD;          // UCA1TXD UART operation set to 1
    P4SEL1 &= ~UCA1TXD;         // UCA1TXD UART operation

    // P4 PIN 3
    P4SEL0 |= UCA1RXD;          // UCA1RXD UART operation st to 1
    P4SEL1 &= ~UCA1RXD;         // UCA1RXD UART operation

    // P4 PIN 4
    P4SEL0 &= ~UCB1_CS_LCD;     // UCB1_CS_LCD GPIO operation to 0
    P4SEL1 &= ~UCB1_CS_LCD;     // UCB1_CS_LCD GPIO operation to 0
    P4OUT |= UCB1_CS_LCD;       // Set SPI_CS_LCD Off [High]
    P4DIR |= UCB1_CS_LCD;       // Set SPI_CS_LCD direction to output

    // P4 PIN 5
    P4SEL0 |= UCB1CLK;          // UCB1CLK SPI BUS operation
    P4SEL1 &= ~UCB1CLK;         // UCB1CLK SPI BUS operation

    // P4 PIN 6
    P4SEL0 |= UCB1SIMO;         // UCB1SIMO SPI BUS operation set to 1
    P4SEL1 &= ~UCB1SIMO;        // UCB1SIMO SPI BUS operation set to 0

    // P4 PIN 7
    P4SEL0 |= UCB1SOMI;         // UCB1SOMI SPI BUS operation set to 1
    P4SEL1 &= ~UCB1SOMI;        // UCB1SOMI SPI BUS operation set to 0
}

//initializing the pins of port 5
void Init_Port5(void) {
    P5OUT = 0x00;               // p5 set Low
    P5DIR = 0x00;               // Set P5 direction to input

    //P5 PIN 0
    P5SEL0 &= ~CHECK_BAT;       // CHECK_BAT GPIO operation (set to 0)
    P5SEL1 &= ~CHECK_BAT;       // CHECK_BAT GPIO operation (set to 0)
    //P5OUT &= ~CHECK_BAT;        //set CHECK_BAT direction to input
    P5DIR &= ~CHECK_BAT;         //set as input
    
    //P5 PIN 1
    P5SEL0 &= ~V_BAT;           // V_BAT GPIO operation (set to 0)
    P5SEL1 &= ~V_BAT;           // V_BAT GPIO operation (set to 0)
    P5OUT |= V_BAT;            //set V_BAT direction to output
    P5DIR |= V_BAT;             //set the output high

    //P5 PIN 2
    P5SEL0 &= ~V_DAC;           // V_DAC GPIO operation (set to 0)
    P5SEL1 &= ~V_DAC;           // V_DAC GPIO operation (set to 0)
    P5OUT |= V_DAC;            //set V_DAC direction to output
    P5DIR |= V_DAC;             //Set the output hight
    
    //P5 PIN 3
    P5SEL0 &= ~V_3_3;           // V_3_3 GPIO operation (set to 0)
    P5SEL1 &= ~V_3_3;           // V_3_3 GPIO operation (set to 0)
    P5OUT |= V_3_3;            //set V_3_3 direction to input
    P5DIR |= V_3_3;             //set the output high
    
    //P5 PIN 4
    P5SEL0 &= ~IOT_PROG_MODE;   // IOT_PROG_MODE GPIO operation (set to 0)
    P5SEL1 &= ~IOT_PROG_MODE;   // IOT_PROG_MODE GPIO operation (set to 0)
    P5DIR &= ~IOT_PROG_MODE;    //IOT_PROG_MODE direction to input
}

//initializing the pins of port 6
void Init_Port6(void) {
    P6OUT = 0x00;               // P6 set Low
    P6DIR = 0x00;               // Set P6 direction to input
    
    //set the capture compare regiisters to 0
    RIGHT_FORWARD_SPEED = WHEEL_OFF;     //(TB3CCR1)
    LEFT_FORWARD_SPEED = WHEEL_OFF;      //(TB3CCR2)
    RIGHT_REVERSE_SPEED = WHEEL_OFF;     //TB3CCR3)
    LEFT_REVERSE_SPEED = WHEEL_OFF;     //(TB3CCR4)

    //P6 PIN 0
    P6SEL0 |= R_FORWARD;       // R_FORWARD TB3.1 operation (set to 1)
    P6SEL1 &= ~R_FORWARD;       // R_FORWARD GPIO operation (set to 0)
    //P6OUT &= ~R_FORWARD;       // OUTPUT set Low
    P6DIR |= R_FORWARD;         // direction set 1 for output

    //P6 PIN 1
    P6SEL0 |= L_FORWARD;       // L_FORWARD TB3.2 operation (set to 1)
    P6SEL1 &= ~L_FORWARD;       // L_FORWARD GPIO operation (set to 0)
    //P6OUT &= ~L_FORWARD;       // OUTPUT set Low
    P6DIR |= L_FORWARD;         // direction set 1 for output

    //P6 PIN 2
    P6SEL0 |= R_REVERSE;       // R_REVERSE TB3.3 operation (set to 1)
    P6SEL1 &= ~R_REVERSE;       // R_REVERSE GPIO operation (set to 0)
    //P6OUT &= ~R_REVERSE;       // OUTPUT set Low
    P6DIR |= R_REVERSE;         // direction set 1 for output

    //P6 PIN 3
    P6SEL0 |= L_REVERSE;       // R_REVERSE TB3.4 operation (set to 1)
    P6SEL1 &= ~L_REVERSE;       // R_REVERSE GPIO operation (set to 0)
    //P6OUT &= ~L_REVERSE;       // OUTPUT set Low
    P6DIR |= L_REVERSE;         // direction set 1 for output

    //P6 PIN 4
    P6SEL0 &= ~LCD_BACKLITE;    // LCD_BACKLITE GPIO operation (set to 0)
    P6SEL1 &= ~LCD_BACKLITE;    // LCD_BACKLITE GPIO operation (set to 0)
    P6OUT &= ~LCD_BACKLITE;    // LCD_BACKLITE set Low
    P6DIR |= LCD_BACKLITE;      // direction set 1 for output

    //P6 PIN 5
    P6SEL0 &= ~P6_5;            // P6_5 GPIO operation (set to 0)
    P6SEL1 &= ~P6_5;            // P6_5 GPIO operation (set to 0)
    P6DIR &= ~P6_5;             // direction set 1 for output

    //P6 PIN 6
    P6SEL0 &= ~GRN_LED;         // GRN_LED GPIO operation (set to 0)
    P6SEL1 &= ~GRN_LED;         // GRN_LED GPIO operation (set to 0)
    P6OUT &= ~GRN_LED;         // GRN_LED set Low
    P6DIR |= GRN_LED;           // direction set 1 for output
}
//------------------------------------------------------------------------------



