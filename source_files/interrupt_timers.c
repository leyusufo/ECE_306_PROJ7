//------------------------------------------------------------------------------
//
//  Description: This file contains timerB interrupts
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

//variables for timer0ccro
unsigned int Time_Sequence=RESET_STATE;
extern volatile unsigned char update_display;
char one_time=RESET_STATE;

//variables for timer0ccr1 and ccr2
extern unsigned int display_changer=RESET_STATE;
extern unsigned int debounce_sw1;//variables for timer0ccr1
extern unsigned int debounce_sw2;//variables for timer0ccr2

//variables for timer1ccr0
extern unsigned int ADC_Left_Array[8]={RESET_STATE};
extern unsigned int ADC_Right_Array[8]={RESET_STATE};
extern unsigned int ADC_Thumb_Array[8]={RESET_STATE};
unsigned int sample_index = RESET_STATE;
extern unsigned int ADC_Left_Detect;
extern unsigned int ADC_Right_Detect;
extern unsigned int ADC_Thumb_Detect;
extern unsigned int ADC_Left_Detect_Avg;
extern unsigned int ADC_Right_Detect_Avg;
extern unsigned int ADC_Thumb_Detect_Avg;
extern char changeDisplay=RESET_STATE;
extern char new_ADC_reading;
extern char average_flag;

//timerB2
unsigned int Time_Sequence_Aclk=RESET_STATE;
unsigned int t1ccr2_counter=RESET_STATE;

extern char start_wheels;
extern unsigned int t1ccr2_flag=RESET_STATE;
//dac
extern unsigned int DAC_data;

//TimerB0 interrupts
//------------------------------------------------------------------------------
//TimerB0 0 interrupt handler
#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer0_B0_ISR(void){
  //add what needs to happen in the interrupt
  // Time Sequence
  one_time = TRUE;
  
  //time sequence
  if(Time_Sequence++ > 250){
    Time_Sequence = RESET_STATE;
  }
  
  //to update display every 200ms
  if(display_changer++ > 5){
    update_display = TRUE;
  }
  
  TB0CCR0 += TB0CCR0_INTERVAL;//add offset to TBCCR0
}

//timerB0 1-2, overflow interrupt vector (TBIV) handler
#pragma vector = TIMER0_B1_VECTOR
__interrupt void TIMER0_B1_ISR(void){
  switch(__even_in_range(TB0IV, 14)){//__even_in_range because TimerB=even interval
  case 0: break; 
  case 2:     
    if(debounce_sw1++ > 3){
      TB0CCTL1 &= ~CCIE;                  //CCR1 disable interrupt
      P4IFG &= ~SW1;                    //clear my flag
      P4IE |= SW1;                        //enable switch interrupt
    }
    TB0CCR1 += TB0CCR1_INTERVAL;  //add offset to TBCCR0
    break;
  case 4:
    if(debounce_sw2++ > 3){
      TB0CCTL2 &= ~CCIE;                  //CCR2 disable interrupt
      P2IFG &= ~SW2;                      //clear my flag
      P2IE |= SW2;                        //enable switch interrupt
    }
    TB0CCR2 += TB0CCR2_INTERVAL;  //add offset to TBCCR0
    break;
  case 14: break;                       //overflow
  default: break;                       
  }
}
//------------------------------------------------------------------------------

//TimerB1 interrupts
//------------------------------------------------------------------------------
//TimerB1 0 interrupt handler
#pragma vector = TIMER1_B0_VECTOR
__interrupt void Timer1_B0_ISR(void){
  //add what needs to happen in the interrupt
  if(start_wheels++==2){
    RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM_MEDIUM;
    LEFT_FORWARD_SPEED = LEFT_FORWARD_PWM_MEDIUM;
    TB1CCTL0 &= ~CCIE;             //CCR0 disable interrupt
  }
  TB1CCR0 += TB1CCR0_INTERVAL;        //add offset to TBCCR0
}

//timerB1 1-2, overflow interrupt vector (TBIV) handler
#pragma vector = TIMER1_B1_VECTOR
__interrupt void TIMER1_B1_ISR(void){
  switch(__even_in_range(TB1IV, 14)){
  case 0: break;                        //no interrupt
  case 2:
    new_ADC_reading = TRUE;
    TB1CCTL1 &= ~CCIE;                  //CCR1 disable interrupt
    ADC_Left_Array[sample_index]=ADC_Left_Detect;
    ADC_Right_Array[sample_index]=ADC_Right_Detect;
    ADC_Thumb_Array[sample_index]=ADC_Thumb_Detect;
    
    
    if(sample_index++ < SAMPLE_SIZE){
      ADCMCTL0 |= ADCINCH_2;              //V_Left_Detect (0x20) Pin 2 A2
      ADCCTL0 |= ADCENC;                  // Enable Conversions
      ADCCTL0 |= ADCSC;                   // ADC start conversion
    }
    else{
      ADC_Left_Detect_Avg = ADC_Left_Array[0]+ADC_Left_Array[1]+ADC_Left_Array[2]+ADC_Left_Array[3]+ADC_Left_Array[4]+ADC_Left_Array[5]+ADC_Left_Array[6]+ADC_Left_Array[7];
      ADC_Left_Detect_Avg = ADC_Left_Detect_Avg >> 3;
      ADC_Right_Detect_Avg = ADC_Right_Array[0]+ADC_Right_Array[1]+ADC_Right_Array[2]+ADC_Right_Array[3]+ADC_Right_Array[4]+ADC_Right_Array[5]+ADC_Right_Array[6]+ADC_Right_Array[7];
      ADC_Right_Detect_Avg = ADC_Right_Detect_Avg >> 3;
      ADC_Thumb_Detect_Avg = ADC_Thumb_Array[0]+ADC_Thumb_Array[1]+ADC_Thumb_Array[2]+ADC_Thumb_Array[3]+ADC_Thumb_Array[4]+ADC_Thumb_Array[5]+ADC_Thumb_Array[6]+ADC_Thumb_Array[7];
      ADC_Thumb_Detect_Avg = ADC_Thumb_Detect_Avg >> 3; //divide by 8
      sample_index = RESET_STATE;
      changeDisplay = TRUE;
      average_flag = TRUE;
    }
/*
    if((t1ccr2_flag==9)){
        //when the detectors are  greater than 400
        if((ADC_Left_Detect>=500)&&(ADC_Right_Detect>=500)){
          RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM_LOW;
          LEFT_FORWARD_SPEED = LEFT_FORWARD_PWM_LOW;
        }
        //when the detectors are between 499-400 
        else if((ADC_Left_Detect<500)&&(ADC_Left_Detect>=400)){
          if((ADC_Left_Detect-ADC_Right_Detect)>75){
            RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM_LOW;
            LEFT_FORWARD_SPEED = LEFT_FORWARD_PWM_LOWEST;
          }
          else{
            Motors_Off();
          }
        }
        else if((ADC_Right_Detect<500)&&(ADC_Right_Detect>=400)){
          if((ADC_Right_Detect-ADC_Left_Detect)>75){
            RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM_LOWEST;
            LEFT_FORWARD_SPEED = LEFT_FORWARD_PWM_LOW;
          }
          else{
            Motors_Off();
          }
        }
        //when the detectors are btw 399-300
        else if((ADC_Left_Detect<400)&&(ADC_Left_Detect>=300)){
          if((ADC_Left_Detect-ADC_Right_Detect)>75){
            RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM_LOW;
            LEFT_FORWARD_SPEED = LEFT_FORWARD_PWM_LOWEST;
          }
          else{
            //Motors_Off();
            RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM_LOW;
            LEFT_FORWARD_SPEED = LEFT_FORWARD_PWM_LOWEST;
          }
        }
        else if((ADC_Right_Detect<400)&&(ADC_Right_Detect>=300)){
          if((ADC_Right_Detect-ADC_Left_Detect)>75){
            RIGHT_FORWARD_SPEED =RIGHT_FORWARD_PWM_LOWEST;
            LEFT_FORWARD_SPEED = LEFT_FORWARD_PWM_LOW;
          }
          else{
            Motors_Off();
          }
        }
        //else{Motors_Off();}
        //when the detectors are btw 300-200
        else if((ADC_Left_Detect<300)&&(ADC_Left_Detect>=200)){
          if((ADC_Left_Detect-ADC_Right_Detect)>75){
            RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM_LOW;
            LEFT_FORWARD_SPEED = WHEEL_OFF;
          }
          else{
            Motors_Off();
          }
        }
        else if((ADC_Right_Detect<300)&&(ADC_Right_Detect>=200)){
          if((ADC_Right_Detect-ADC_Left_Detect)>75){
            RIGHT_FORWARD_SPEED = WHEEL_OFF;
            LEFT_FORWARD_SPEED = LEFT_FORWARD_PWM_LOW;
          }
          else{
            Motors_Off();
          }
        }
        //when the detctors are btw 200-100
        else if((ADC_Left_Detect<200)&&(ADC_Left_Detect>=100)){
          if((ADC_Left_Detect>ADC_Right_Detect)){
            RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM_LOW;
            LEFT_FORWARD_SPEED = WHEEL_OFF;
          }
          else{
            Motors_Off();
          }
        }
        else if((ADC_Right_Detect<200)&&(ADC_Right_Detect>=100)){
          if((ADC_Right_Detect>ADC_Left_Detect)){
            RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM_LOWEST;
            LEFT_FORWARD_SPEED = LEFT_FORWARD_PWM_LOW;
          }
          else{
            Motors_Off();
          }
        }
        //new
        else if((ADC_Right_Detect<100)&&(ADC_Right_Detect>=70)){
          if((ADC_Right_Detect>ADC_Left_Detect)){
            RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM_LOWEST;
            LEFT_FORWARD_SPEED = LEFT_FORWARD_PWM_LOW;
          }
          else{
            Motors_Off();
          }
        }
        else if((ADC_Left_Detect<100)&&(ADC_Left_Detect>=70)){
          if((ADC_Left_Detect>ADC_Right_Detect)){
            RIGHT_FORWARD_SPEED = LEFT_FORWARD_PWM_LOW;
            LEFT_FORWARD_SPEED = RIGHT_FORWARD_PWM_LOWEST;
          }
          else{
            Motors_Off();
          }
        }
        else{
          Motors_Off();
        }   
    }*/
    TB1CCR1 += TB1CCR1_INTERVAL;
    break;
  case 4:
    switch(t1ccr2_counter){
    case 0:break;
    case 4:
      Reverse_Left_Motor_On();
      RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM_LOW;
      break;
    case 7://****************************************/
      Motors_Off();
       TB1CCTL2 &= ~CCIE;
      //TB1CCTL2 &= ~CCIE;
      break;
    case 8:
      RIGHT_FORWARD_SPEED = RIGHT_FORWARD_PWM_MEDIUM;
      //t1ccr2_flag= 7;
      //TB1CCTL2 &= ~CCIE;
      break;
    case 10:
      Motors_Off();
      //TB1CCTL2 &= ~CCIE;
      break;
    case 12:
      t1ccr2_flag= 9;
      TB1CCTL2 &= ~CCIE;
      break;
    case 13:
      break;
    case 14://************************
      break;
    default:break;
    }
    t1ccr2_counter++;
    TB1CCR2 += TB1CCR2_INTERVAL;        //Add offset to TBCCR2
    break;
  case 14: break;                       //overflow
  default: break;                       
  }
}
//------------------------------------------------------------------------------

//TimerB2 interrupts
//------------------------------------------------------------------------------
//TimerB2 0 interrupt handler
#pragma vector = TIMER2_B0_VECTOR
__interrupt void Timer2_B0_ISR(void){
  //add what needs to happen in the interrupt
  Time_Sequence_Aclk++;
  //TB2CCTL0 &= ~CCIE;             //CCR0 disable interrupt
  TB2CCR0 += TB2CCR0_INTERVAL;  //add offset to TBCCR0
 
}

//timerB2 1-2, overflow interrupt vector (TBIV) handler
#pragma vector = TIMER2_B1_VECTOR
__interrupt void TIMER2_B1_ISR(void){
  switch(__even_in_range(TB2IV, 14)){
  case 0: break;                        //no interrupt
  case 2:
    //decrement the DAC voltage to 1000
    if(DAC_data > 1000){  // after running check
      DAC_data = DAC_data - 100;
      SAC3DAT = DAC_data;
      TB2CCR1 += TB2CCR1_INTERVAL;        // Add offset to TBCCR1
    }
    else{
      TB2CCTL1 &= ~CCIE;                  // CCR0 disable interrupt
    }
    break;
  case 4:
    //TB2CCR2 += TB2CCR2_INTERVAL;        //Add offset to TBCCR2
    break;
  case 14: break;                       //overflow
  default: break;                       
  }
}
//------------------------------------------------------------------------------

//TimerB3 interrupts
//------------------------------------------------------------------------------
//TimerB3 0 interrupt handler
#pragma vector = TIMER3_B0_VECTOR
__interrupt void Timer3_B0_ISR(void){
  //add what needs to happen in the interrupt
}

//timerB3 1-2, overflow interrupt vector (TBIV) handler
#pragma vector = TIMER3_B1_VECTOR
__interrupt void TIMER3_B1_ISR(void){
  switch(__even_in_range(TB3IV, 14)){
  case 0: break;
  case 2: break;         //no interrupt for TBCCR1
  case 4: break;         //no interrupt for TBCCR2
  case 6: break;         //no interrupt for TBCCR3
  case 8: break;         //no interrupt for TBCCR4
  case 10: break;       //no interrupt for TBCCR5
  case 12: break;       //no interrupt for TBCCR5
  case 14: break;       //overflow
  default: break;                       
  }
}
//------------------------------------------------------------------------------