//------------------------------------------------------------------------------
//
//  Description: This file contains DAC functions
//
//
//  Loyda Yusufova
//  2021
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//------------------------------------------------------------------------------

#include  "functions.h"
#include  "macros.h"
#include  "msp430.h"
#include "ports.h"

unsigned int DAC_data=RESET_STATE;

//DAC initialization
//------------------------------------------------------------------------------
//function that sets the internal reference for the DAC
void Init_REF(void){
  // Configure reference module
  PMMCTL0_H = PMMPW_H;          // Unlock the PMM registers
  PMMCTL2 = INTREFEN;           // Enable internal reference
  PMMCTL2 |= REFVSEL_2;         // Select 2.5V reference
  while(!(PMMCTL2 & REFGENRDY)){ // Poll till internal reference settles
    ;
  }
  // Using a while statement is not usually recommended without an exit strategy.
  // This while statement is the suggested operation to allow the reference to settle.
}

//function that intitializes the DAC
void Init_DAC(void){
  DAC_data = INITIAL_VAL_DAC;   // Value between 0x000 and 0x0FFF
  SAC3DAT = DAC_data;           // Initial DAC data-this is the initial value for the DAC
  SAC3DAC = DACSREF_1;          // Select int Vref as DAC reference
  SAC3DAC |= DACLSEL_0;         // DAC latch loads when DACDAT written
  // SAC3DAC |= DACIE;          // generate an interrupt
  
  // This reconfigures th port pins for DAC
  P3SEL0 |=  DAC_CNTL;                // DAC_CNTL DAC operation
  P3SEL1 &= ~DAC_CNTL;                // DAC_CNTL DAC operation
  
  SAC3DAC |= DACEN;             // Enable DAC
  SAC3OA = NMUXEN;              // SAC Negative input MUX controL
  SAC3OA |= PMUXEN;             // SAC Positive input MUX control 
  SAC3OA |= PSEL_1;             // 10-bit reference DAC source selected
  SAC3OA |= NSEL_1;             // Select negative pin input
  SAC3OA |= OAPM;               // Select low speed and low power mode
  SAC3PGA = MSEL_1;             // Set OA as buffer mode 
  SAC3OA |= SACEN;              // Enable SAC
  SAC3OA |= OAEN;               // Enable OA
}
//------------------------------------------------------------------------------

//routine that sets the DAC to 2000
//------------------------------------------------------------------------------
void set_DAC_1200(void){
  TB2CCTL1 &= ~CCIFG;             //clear possible pending interrupt
  TB2CCR1 = TB2R + TB2CCR1_INTERVAL;   //CCR2
  TB2CCTL1 |= CCIE;             //CCR2 enable interrupt
}
