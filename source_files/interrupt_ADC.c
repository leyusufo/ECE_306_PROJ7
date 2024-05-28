//------------------------------------------------------------------------------
//
//  Description: This file contains interrupt for ADC
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

unsigned int ADC_Channel=RESET_STATE;
unsigned int ADC_Left_Detect=RESET_STATE;
unsigned int ADC_Right_Detect=RESET_STATE;
unsigned int ADC_Thumb_Detect=RESET_STATE;

#pragma vector=ADC_VECTOR
__interrupt void ADC_ISR(void){
  switch(__even_in_range(ADCIV,ADCIV_ADCIFG)){
  case ADCIV_NONE:
    break;
  case ADCIV_ADCOVIFG:          // When a conversion result is written to the ADCMEM0
    // before its previous conversion result was read.
    break;
  case ADCIV_ADCTOVIFG:         // ADC conversion-time overflow
    break;
  case ADCIV_ADCHIIFG:          // Window comparator interrupt flags
    break;
  case ADCIV_ADCLOIFG:          // Window comparator interrupt flag
    break;
  case ADCIV_ADCINIFG:          // Window comparator interrupt flag
    break;
  case ADCIV_ADCIFG:            // ADCMEM0 memory register with the conversion result
    ADCCTL0 &= ~ADCENC;         // Disable ENC bit.
    switch (ADC_Channel++){
    case 0x00:                          // Channel A2 Interrupt
      ADCMCTL0 &= ~ADCINCH_2;           // Disable Last channel A2
      ADCMCTL0 |= ADCINCH_3;            // Enable Next channel A3
      ADC_Left_Detect = ADCMEM0;        // Move result into Global
      ADCCTL0 |= ADCENC;                  // Enable Conversions
      ADCCTL0 |= ADCSC;                   // ADC start conversion*/
      break;
    case 0x01:
      ADCMCTL0 &= ~ADCINCH_3;           // Disable Last channel A3
      ADCMCTL0 |= ADCINCH_5;            // Enable Next channel A5
      ADC_Right_Detect = ADCMEM0;        // Move result into Global
      ADCCTL0 |= ADCENC;                  // Enable Conversions
      ADCCTL0 |= ADCSC;                  // ADC start conversion*/
      break;
    case 0x02:
      ADCMCTL0 &= ~ADCINCH_5;                   //disable channel 5
      ADCMCTL0 |= ADCINCH_2;                    // enable channel A2
      ADC_Thumb_Detect = ADCMEM0;               // Move result into Global
      ADC_Channel=RESET_STATE;
      TB1CCTL1 &= ~CCIFG;                       //clear any pending interrupts for TimerB0 CCR1
      TB1CCR1 = TB1R + TB1CCR1_INTERVAL;        //add interval for TB1CCR1
      TB1CCTL1 |= CCIE;                         //CCR1 enable interrupt 25ms
      break;
    default:
      break;
    }
    break;
      
  default:
    break;
  }
}
