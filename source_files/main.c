//------------------------------------------------------------------------------
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Loyda Yusufova
//  2021
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "functions.h"
#include  "macros.h"
#include  "msp430.h"
#include <string.h>
#include "ports.h"

// Global Variables
extern char display_line[4][11];
extern char *display[4];
extern unsigned char display_mode;
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;

void main(void){
  //------------------------------------------------------------------------------
  // Main Program
  // This is the main routine for the program. Execution of code starts here.
  // The operating system is Back Ground Fore Ground.
  //
  //------------------------------------------------------------------------------
  // Disable the GPIO power-on default high-impedance mode to activate
  // previously configured port settings
  //turn the light on your LCD on
  
  PM5CTL0 &= ~LOCKLPM5;
  Init_Ports();                        // Initialize Ports
  Init_Clocks();                       // Initialize Clock System
  Init_Conditions();                   // Initialize Variables and Initial Conditions
  Init_LCD();                          // Initialize LCD
  Init_Timers();                       // Initialize Timers
  
  P4OUT |= RESET_LCD;        // Set RESET_LCD On [high]
  P6OUT |= LCD_BACKLITE;
  
  Init_ADC();           //initiate ADC 
  Init_REF();           //initiate internal reference for DAC
  Init_DAC();           //initiate the DAC
  set_DAC_1200();       //sets the DAC to 2000 incrementing decrementing by 100 with timer
  
  //------------------------------------------------------------------------------
  // Begining of the "While" Operating System
  //------------------------------------------------------------------------------
  while(ALWAYS) {               // Can the Operating system run
    black_line_found();         //checks if the black line has been found and stops the car
    new_average_ADC();          //checks if there is a new average of ADC readings
    wheel_Safety_Check();       //checks for wheel safety
    Display_Process();
  }
}