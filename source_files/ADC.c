#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"
//#include "ports.h"

extern char changeDisplay;
unsigned int ADC_Left_Detect_Avg=RESET_STATE;
unsigned int ADC_Right_Detect_Avg=RESET_STATE;
unsigned int ADC_Thumb_Detect_Avg=RESET_STATE;
unsigned int old_ADC_Left_Detect=RESET_STATE;
unsigned int old_ADC_Right_Detect=RESET_STATE;
unsigned int old_ADC_Thumb_Detect=RESET_STATE;
extern unsigned int ADC_Left_Detect;
extern unsigned int ADC_Right_Detect;
extern unsigned int ADC_Thumb_Detect;
extern volatile unsigned char display_changed;
char new_ADC_reading=RESET_STATE;
extern char average_flag=RESET_STATE;

extern char display_line[4][11];
extern char BDC_value[4];

//ADC initialization 
//------------------------------------------------------------------------------
void Init_ADC(void){
  
  // V_DETECT_L (0x04) //Pin 2 A2
  // V_DETECT_R (0x08) //Pin 3 A3
  // V_THUMB (0x20) //Pin 5 A5
  
  // ADCCTL0 Register
  ADCCTL0 = 0;            //Reset
  ADCCTL0 |= ADCSHT_2;    //16 ADC clocks
  ADCCTL0 |= ADCMSC;      //MSC
  ADCCTL0 |= ADCON;       //ADC ON
  
  //ADCCTL1 Register
  ADCCTL1 = 0;            // Reset
  ADCCTL1 |= ADCSHS_0;    //00b = ADCSC bit
  ADCCTL1 |= ADCSHP;      //ADC sample-and-hold SAMPCON signal from sampling timer.
  ADCCTL1 &= ~ADCISSH;    //ADC invert signal sample-and-hold.
  ADCCTL1 |= ADCDIV_0;    //ADC clock divider - 000b = Divide by 1
  ADCCTL1 |= ADCSSEL_0;   //ADC clock MODCLK
  ADCCTL1 |= ADCCONSEQ_0; //ADC conversion sequence 00b = Single-channel single-conversion
  //ADCCTL1 & ADCBUSY identifies a conversion is in process
  
  //ADCCTL2 Register
  ADCCTL2 = 0;            //Reset
  ADCCTL2 |= ADCPDIV0;    //ADC pre-divider 00b = Pre-divide by 1
  ADCCTL2 |= ADCRES_1;    //ADC resolution 10b = 12 bit (14 clock cycle conversion time)
  ADCCTL2 &= ~ADCDF;      //ADC data read-back format 0b = Binary unsigned.
  ADCCTL2 &= ~ADCSR;      //ADC sampling rate 0b = ADC buffer supports up to 200 ksps
  
  //ADCMCTL0 Register
  ADCMCTL0 |= ADCSREF_0;  //VREF - 000b = {VR+ = AVCC and VR– = AVSS }
  ADCMCTL0 |= ADCINCH_2;  //V_THUMB (0x20) Pin 5 A5
  ADCIE |= ADCIE0;        //Enable ADC conv complete interrupt
  ADCCTL0 |= ADCENC;      //ADC enable conversion.
  ADCCTL0 |= ADCSC;       //ADC start conversion.
}
//------------------------------------------------------------------------------

void ADC_readings(void){
  //displays the DAC readings for detectors
  if((changeDisplay == TRUE)){
    if(ADC_Left_Detect_Avg != old_ADC_Left_Detect){
      HEXtoBCD(ADC_Left_Detect_Avg);        // Convert result to String
      display_ADC_left_detect();
    }
    if(ADC_Right_Detect_Avg != old_ADC_Right_Detect){
      HEXtoBCD(ADC_Right_Detect_Avg);        // Convert result to String
      display_ADC_right_detect();
    }
    
    display_changed = TRUE;                   //change the display
    old_ADC_Left_Detect = ADC_Left_Detect_Avg;//save current value
    old_ADC_Right_Detect = ADC_Right_Detect_Avg;//save current value
    old_ADC_Thumb_Detect = ADC_Thumb_Detect_Avg;  //save current value
    changeDisplay=RESET_STATE;           //dont change display until next reading
    ADCMCTL0 |= ADCINCH_2;              //V_Left_Detect (0x20) Pin 2 A2
    ADCCTL0 |= ADCENC;                  // Enable Conversions
    ADCCTL0 |= ADCSC;                   // ADC start conversion
  }
}


int ADC_movement(void){
  if(new_ADC_reading){
    if((ADC_Left_Detect<65)&&(ADC_Right_Detect<65)){
      return 0;
    } 
    if((ADC_Left_Detect>200)&&(ADC_Right_Detect>200)){
      return 1;
    }
    if(ADC_Left_Detect>400){
      if((ADC_Left_Detect-ADC_Right_Detect)>200){
        return 2;
      }
    }
    if(ADC_Right_Detect>400){
      if((ADC_Right_Detect-ADC_Left_Detect)>200){
        return 3;
      }
    }
    new_ADC_reading=FALSE;
  }
  
  return 10;
}

void new_average_ADC(void){
  if((average_flag==TRUE)){
    ADC_readings();
    average_flag=FALSE;
  }
}