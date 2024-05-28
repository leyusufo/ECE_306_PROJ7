//------------------------------------------------------------------------------
//
//  Description: This file contains the routines for motors
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
//#include <string.h>
//#include "ports.h"

extern char start_wheels;
extern unsigned int t1ccr2_counter;

//motor initialization
//------------------------------------------------------------------------------
void Init_Motors(void){
  RIGHT_FORWARD_SPEED = WHEEL_OFF;
  LEFT_FORWARD_SPEED = WHEEL_OFF;
  RIGHT_REVERSE_SPEED = WHEEL_OFF; 
  LEFT_REVERSE_SPEED = WHEEL_OFF;
}
//------------------------------------------------------------------------------

//all motors off
void Motors_Off(void){
  RIGHT_FORWARD_SPEED = WHEEL_OFF;
  LEFT_FORWARD_SPEED = WHEEL_OFF;
  RIGHT_REVERSE_SPEED = WHEEL_OFF; 
  LEFT_REVERSE_SPEED = WHEEL_OFF;
}
//forward motors on
void Forward_Motors_On(void){
  RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM;
  LEFT_FORWARD_SPEED = LEFT_FORWARD_PWM;
}
//reverse motos on
void Reverse_Motors_On(void){
  RIGHT_REVERSE_SPEED = RIGHT_REVERSE_PWM; 
  LEFT_REVERSE_SPEED = LEFT_REVERSE_PWM;
}
//forward motors off
void Forward_Motors_Off(void){
  RIGHT_FORWARD_SPEED = WHEEL_OFF;
  LEFT_FORWARD_SPEED = WHEEL_OFF;
}
//reverse movement off
void Reverse_Motors_Off(void){
  RIGHT_REVERSE_SPEED = WHEEL_OFF; 
  LEFT_REVERSE_SPEED = WHEEL_OFF;
}
//right forward movement
void Forward_Right_Motor_On(void){
  RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM;
}
//turn right movement off
void Forward_Right_motor_Off(void){
  RIGHT_FORWARD_SPEED = WHEEL_OFF;
}
//turn left movement on
void Forward_Left_Motor_On(void){
  LEFT_FORWARD_SPEED = LEFT_FORWARD_PWM;
}
//left movement off only
void Forward_Left_Motor_Off(void){
  LEFT_FORWARD_SPEED = WHEEL_OFF;
}
//right reverse movement
void Reverse_Right_Motor_On(void){
  RIGHT_REVERSE_SPEED = RIGHT_REVERSE_PWM;
}
//turn right reverse movement off
void Reverse_Right_motor_Off(void){
  RIGHT_REVERSE_SPEED = WHEEL_OFF;
}
//turn left reverse movement on
void Reverse_Left_Motor_On(void){
  LEFT_REVERSE_SPEED = LEFT_REVERSE_PWM;
}
//left reverse movement off only
void Reverse_Left_Motor_Off(void){
  LEFT_REVERSE_SPEED = WHEEL_OFF;
}

void wheel_Safety_Check(void){
  //wheel safety check

  unsigned int temp_right_forward;
  unsigned int temp_left_forward;

  temp_right_forward = RIGHT_FORWARD_SPEED;
  temp_left_forward = LEFT_FORWARD_SPEED;

  if(temp_right_forward & RIGHT_REVERSE_SPEED){
    RIGHT_FORWARD_SPEED = WHEEL_OFF;
    RIGHT_REVERSE_SPEED = WHEEL_OFF;
    Red_LED_On();

  }
  if(temp_left_forward & LEFT_REVERSE_SPEED){
    LEFT_FORWARD_SPEED = WHEEL_OFF;
    LEFT_REVERSE_SPEED = WHEEL_OFF;
    Red_LED_On();
  }
}

void black_line_found(void){
  if((ADC_movement()==1)&&(start_wheels>=2)){
    Motors_Off();
    start_wheels = RESET_STATE;
    
    
    TB1CCTL2 &= ~CCIFG;             //clear possible pending interrupt
    TB1CCR2 = TB1R + TB1CCR2_INTERVAL;   //CCR2
    TB1CCTL2 |= CCIE;             //CCR2 enable interrupt
    t1ccr2_counter = RESET_STATE;
  }
}