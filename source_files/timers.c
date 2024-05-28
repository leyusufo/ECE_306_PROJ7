#include  "functions.h"
#include  "macros.h"
#include  "msp430.h"

extern unsigned int Time_Sequence;

//initialize all the timers
void Init_Timers(void){
  Time_Sequence = 0;
  Init_Timer_B0();
  Init_Timer_B1();
  Init_Timer_B2();
  Init_Timer_B3();
}
//timer B0 initialization sets B0, B1, B2, and overflow
//--------------------------------------------------------------------------------------------------------
void Init_Timer_B0(void){
  TB0CTL = RESET_STATE;       //clear TBO control register
  TB0EX0 = RESET_STATE;         //CLEAR TBIDEX register
  TB0CTL = TBSSEL__SMCLK;       //setting SMCLK as a source clock
  TB0CTL |= MC__CONTINUOUS;     //counts up to 65535 and goes back to zero
  TB0CTL |= ID__8;               //DIVIDE CLOCK BY 8
  TB0EX0 |= TBIDEX__8;            //divide clock by an additional 8
  TB0CTL |= TBCLR;              //resets TB0R, clock divider, count direction (this clears the counter)
  
  TB0CCR0 = TB0CCR0_INTERVAL;   //CCR0
  TB0CCTL0 &= ~CCIFG;           //clear possible pending interrupt
  TB0CCTL0 |= CCIE;             //CCR0 enable interrupt
  
  TB0CCR1 = TB0CCR1_INTERVAL;   //CCR1
  TB0CCTL1 &= ~CCIFG;            //clear possible pending interrupt
  TB0CCTL1 &= ~CCIE;             //CCR1 disable interrupt
    
  TB0CCR2 = TB0CCR2_INTERVAL;   //CCR2
  TB0CCTL2 &= ~CCIFG;            //clear possible pending interrupt
  TB0CCTL2 &= ~CCIE;             //CCR2 disable interrupt 
  
  TB0CTL &= ~TBIE;              //Disable overflow interrupt
  TB0CTL &= ~TBIFG;             //Clear overflow interrupt flag
}
//--------------------------------------------------------------------------------------------------------

//timer B1 initialization sets B0, B1, B2, and overflow
//--------------------------------------------------------------------------------------------------------
void Init_Timer_B1(void){
  TB1CTL = RESET_STATE;       //clear TBO control register
  TB1EX0 = RESET_STATE;         //CLEAR TBIDEX register
  TB1CTL = TBSSEL__SMCLK;       //setting SMCLK as a source clock
  TB1CTL |= MC__CONTINUOUS;     //counts up to 65535 and goes back to zero
  TB1CTL |= ID__8;               //DIVIDE CLOCK BY 8
  TB1EX0 |= TBIDEX__8;            //divide clock by an additional 8
  TB1CTL |= TBCLR;              //resets TB0R, clock divider, count direction (this clears the counter)
  
  TB1CCR0 = TB1CCR0_INTERVAL;   //CCR0
  TB1CCTL0 &= ~CCIFG;           //clear possible pending interrupt
  TB1CCTL0 &= ~CCIE;             //CCR0 enable interrupt
 
  TB1CCR1 = TB1CCR1_INTERVAL;   //CCR1
  TB1CCTL1 &= ~CCIFG;            //clear possible pending interrupt
  TB1CCTL1 &= ~CCIE;             //CCR1 enable interrupt
    
  TB1CCR2 = TB1CCR2_INTERVAL;   //CCR2
  TB1CCTL2 &= ~CCIFG;             //clear possible pending interrupt
  TB1CCTL2 &= ~CCIE;             //CCR2 enable interrupt 
  
  TB1CTL &= ~TBIE;              //Disable overflow interrupt
  TB1CTL &= ~TBIFG;             //Clear overflow interrupt flag
}
//--------------------------------------------------------------------------------------------------------

//timer B2 initialization sets B0, B1, B2, and overflow
//--------------------------------------------------------------------------------------------------------
void Init_Timer_B2(void){
  TB2CTL = RESET_STATE;       //clear TBO control register
  TB2EX0 = RESET_STATE;         //CLEAR TBIDEX register
  TB2CTL = TBSSEL__ACLK;       //setting ACLK as a source clock
  TB2CTL |= MC__CONTINUOUS;     //counts up to 65535 and goes back to zero
  TB2CTL |= ID__8;               //DIVIDE CLOCK BY 8
  TB2EX0 |= TBIDEX__8;            //divide clock by an additional 8
  TB2CTL |= TBCLR;              //resets TB0R, clock divider, count direction (this clears the counter)
  
  TB2CCR0 = TB2CCR0_INTERVAL;   //CCR0
  TB2CCTL0 &= ~CCIFG;           //clear possible pending interrupt
  TB2CCTL0 &= ~CCIE;             //CCR0 enable interrupt
  
  TB2CCR1 = TB2CCR1_INTERVAL;   //CCR1
  TB2CCTL1 &= ~CCIFG;            //clear possible pending interrupt
  TB2CCTL1 &= ~CCIE;             //CCR1 enable interrupt
    
  TB2CCR2 = TB2CCR2_INTERVAL;   //CCR2
  TB2CCTL2 &= ~CCIFG;             //clear possible pending interrupt
  TB2CCTL2 &= ~CCIE;             //CCR2 enable interrupt 
  
  TB2CTL &= ~TBIE;              //Disable overflow interrupt
  TB2CTL &= ~TBIFG;             //Clear overflow interrupt flag
}
//--------------------------------------------------------------------------------------------------------

//timer B3 initialization sets B0, B1, B2, and overflow
//--------------------------------------------------------------------------------------------------------
void Init_Timer_B3(void){
  // SMCLK source, up count mode, PWM Right Side
  // TB3.1 P6.0 R_FORWARD
  // TB3.2 P6.1 L_FORWARD 
  // TB3.3 P6.2 R_REVERSE
  // TB3.4 P6.3 L_REVERSE
  
  TB3CTL = TBSSEL__SMCLK;       //setting SMCLK as a source clock
  TB3CTL |= MC__UP;             //counts up to WHEEL_PERIOD and goes back to zero
  TB3CTL |= TBCLR;              //resets TB0R, clock divider, count direction (this clears the counter)
  
  //TB3CTL |= ID__2;            //DIVIDE CLOCK BY 2
  //TB3EX0 |=TBIDEX__8;         //divide clock by an additional 8
  
  TB3CCR0 = WHEEL_PERIOD;               //PWM period
  //TB3CCTL0 &= ~CCIFG;                 //clear possible pending interrupt
  //TB3CCTL0 |= CCIE;                   //CCR0 enable interrupt
  
  //TB3CCR1 = TB3CCR1_INTERVAL;         //CCR1
  //TB3CCR1 &= ~CCIFG;                  //clear possible pending interrupt
  TB3CCTL1 = OUTMOD_7;                  //CCR1 enable interrupt
  RIGHT_FORWARD_SPEED = WHEEL_OFF;      //P6.0 RIGHT FORWARD pwm DUTY CYCLE
    
  //TB3CCR2 = TB3CCR2_INTERVAL;         //CCR2
  //TB3CCR2 &= ~CCIFG;                  //clear possible pending interrupt
  TB3CCTL2 = OUTMOD_7;                  //CCR2 enable interrupt 
  LEFT_FORWARD_SPEED = WHEEL_OFF;       //P6.1 left forward pwm ducty cycle
  
  TB3CCTL3 = OUTMOD_7;                  //CCR2 enable interrupt 
  RIGHT_REVERSE_SPEED = WHEEL_OFF;      //P6.3 RIGHT forward pwm ducty cycle
  
  TB3CCTL4 = OUTMOD_7;                  //CCR2 enable interrupt 
  LEFT_REVERSE_SPEED = WHEEL_OFF;       //P6.4 left forward pwm ducty cycle
  
  //TB3CTL &= ~TBIE;                    //Disable overflow interrupt
  //TB3CTL &= ~TBIFG;                   //Clear overflow interrupt flag
}
//--------------------------------------------------------------------------------------------------------