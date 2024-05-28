#include  "functions.h"
#include  "macros.h"
//#include  "msp430.h"

char thousands=RESET_STATE;
char hundreds=RESET_STATE;
char tens=RESET_STATE;
char ones=RESET_STATE;
char BDC_value[4]={RESET_STATE,RESET_STATE,RESET_STATE,RESET_STATE};

void HEXtoBCD(unsigned int value){
  thousands = RESET_STATE;
  hundreds = RESET_STATE;
  tens = RESET_STATE;
  ones = RESET_STATE;
  
  while(value > RESET_STATE){
    if(value >= THOUSANDS){
      value = value - THOUSANDS;
      thousands = thousands + 1;
    }
    else if(value >=HUNDREDS){
      value = value - HUNDREDS;
      hundreds = hundreds + 1;
    }
    else if(value >=TENS){
      value = value - TENS;
      tens = tens + 1;
    }
    else if(value >= 1){
      value = value - 1;
      ones = ones + 1;
    }
    else{;}
  }
  
  thousands = thousands + ZERO_ASCII;
  hundreds = hundreds + ZERO_ASCII;
  tens = tens + ZERO_ASCII;
  ones = ones + ZERO_ASCII;
  
  BDC_value[0] = thousands;
  BDC_value[1] = hundreds;
  BDC_value[2] = tens;
  BDC_value[3] = ones;
}