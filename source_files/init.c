//------------------------------------------------------------------------------
//
//  Description: This file contains a function that sets the initial conditions 
//               for many systems
//
//
//  Loyda Yusufova
//  Febreuary 12
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.20.1)
//------------------------------------------------------------------------------
#include "msp430.h"
#include "macros.h"
#include "functions.h"

//global variable needed
extern char display_line[4][11];
extern char *display[4];
extern volatile unsigned char update_display;
extern unsigned int DAC_data;



//NITIALIZING CONDITIONS FOR THE DISPLAY
//------------------------------------------------------------------------------
void Init_Conditions(void){
  int i;
  
  for(i=0;i<11;i++){
    display_line[0][i] = RESET_STATE;
    display_line[1][i] = RESET_STATE;
    display_line[2][i] = RESET_STATE;
    display_line[3][i] = RESET_STATE;
  }
  
  display_line[0][10] = 0;
  display_line[1][10] = 0;
  display_line[2][10] = 0;
  display_line[3][10] = 0;
  
  display[0] = &display_line[0][0];
  display[1] = &display_line[1][0];
  display[2] = &display_line[2][0];
  display[3] = &display_line[3][0];
  update_display = 0;
  
  // Interrupts are disabled by default, enable them.
  enable_interrupts();
}
//------------------------------------------------------------------------------
