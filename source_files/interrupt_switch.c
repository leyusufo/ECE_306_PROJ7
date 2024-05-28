//------------------------------------------------------------------------------
//
//  Description: This file contains interrupts for switches
//               
//
//
//  Loyda Yusufova
//  Febreuary 12
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.20.1)
//------------------------------------------------------------------------------

#include  "functions.h"
#include  "macros.h"
#include  "msp430.h"
#include "ports.h"

unsigned int debounce_sw1=RESET_STATE;//variables for timer0ccr1
unsigned int debounce_sw2=RESET_STATE;//variables for timer0ccr2
char sw1_pressed=RESET_STATE;
char start_wheels=RESET_STATE;

#pragma vector = PORT4_VECTOR
__interrupt void switchP4_interrupt(void){
  //switch 1
  if(P4IFG & SW1){
    P4IE &= ~SW1;       // P4.1 interrupt disabled Disable the Switch Interrupt (because of bouncing)
    P4IFG &= ~SW1;      //clear the flag
    TB0CCTL1 &= ~CCIFG;  //clear any pending interrupts for TimerB0 CCR1
    TB0CCR1 = TB0R + TB0CCR1_INTERVAL;  //add interval for TB0CCR1
    TB0CCTL1 |= CCIE;             //CCR1 enable interrupt
    debounce_sw1 = 0;             //start the debounce
    
    /*if(P1OUT & RED_LED){
    Red_LED_Off();
  }
    else{
    Red_LED_On();
  }*/
    sw1_pressed=TRUE;
    start_wheels=RESET_STATE;
    TB1CCTL0 &= ~CCIFG;           //clear possible pending interrupt
    TB1CCTL0 |= CCIE;             //CCR0 enable interrupt
  }
}

#pragma vector = PORT2_VECTOR
__interrupt void switchP2_interrupt(void){
  //switch 2
  if(P2IFG & SW2){
    P2IE &= ~SW2;                // P4.1 interrupt disabled-Disable the Switch Interrupt (because of bouncing)
    P2IFG &= ~SW2;      //clear your flag
    TB0CCTL2 &= ~CCIFG;  //clear any pending interrupts for TimerB0 CCR2
    TB0CCR2 = TB0R + TB0CCR2_INTERVAL;  //add interval for TB0CCR1
    TB0CCTL2 |= CCIE;             //CCR2 enable interrupt
    debounce_sw2=0;                     //start the debounce
    
    //DO WHAT U WANNA DO WHEN SWITCH IS PRESSED
    if(P6OUT & GRN_LED){
    GRN_LED_Off();
  }
    else{
    GRN_LED_On();
  }
    if(P2OUT & IR_LED){
      P2OUT &= ~IR_LED;      //turn on IR LED
    }
    else{
      P2OUT |= IR_LED;
    }
  }
}