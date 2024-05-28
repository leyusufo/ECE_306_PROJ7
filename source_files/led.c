//------------------------------------------------------------------------------
//
//  Description: This file contains several functions that control the LEDs
//
//
//  Loyda Yusufova
//  Febreuary 12
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.20.1)
//------------------------------------------------------------------------------
#include  "functions.h"
#include  "msp430.h"
#include "ports.h"

//INITIALIZING LED's (turns them on)
//------------------------------------------------------------------------------
void Init_LEDs(void){
    // LED Configurations
    // Turns off both LEDs
    P1OUT &= ~RED_LED;
    P6OUT &= ~GRN_LED;
}
//------------------------------------------------------------------------------
void Red_LED_Off(void){
    // Turns off red LED
    P1OUT &= ~RED_LED;
}

void Red_LED_On(void){
    // Turns on red LED
    P1OUT |= RED_LED;
}

void GRN_LED_Off(void){
    // Turns off green LED
    P6OUT &= ~GRN_LED;
}

void GRN_LED_On(void){
    // Turns on green LED
    P6OUT |= GRN_LED;
}