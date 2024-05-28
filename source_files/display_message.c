#include  "functions.h"

extern char display_line[4][11];
extern char BDC_value[4];

void blackLineDetected(void){
  display_line[2][0]='B';
  display_line[2][1]='L';
  display_line[2][2]='A';
  display_line[2][3]='C';
  display_line[2][4]='K';
  display_line[2][5]=' ';
  display_line[2][6]='L';
  display_line[2][7]='I';
  display_line[2][8]='N';
  display_line[2][9]='E';
  display_line[2][10]=' ';
  
  display_line[3][0]='D';
  display_line[3][1]='E';
  display_line[3][2]='T';
  display_line[3][3]='E';
  display_line[3][4]='C';
  display_line[3][5]='T';
  display_line[3][6]='E';
  display_line[3][7]='D';
  display_line[3][8]=' ';
  display_line[3][9]=' ';
  display_line[3][10]=' ';
}
void message_left(void){
display_line[3][0]='G';
    display_line[3][1]='O';
    display_line[3][2]='I';
    display_line[3][3]='N';
    display_line[3][4]='G';
    display_line[3][5]=' ';
    display_line[3][6]='L';
    display_line[3][7]='E';
    display_line[3][8]='F';
    display_line[3][9]='T';
    display_line[3][10]=' ';
}
void message_right(void){
  display_line[3][0]='G';
    display_line[3][1]='O';
    display_line[3][2]='I';
    display_line[3][3]='N';
    display_line[3][4]='G';
    display_line[3][5]=' ';
    display_line[3][6]='R';
    display_line[3][7]='I';
    display_line[3][8]='G';
    display_line[3][9]='H';
    display_line[3][10]=' ';
}
void clear_line3_display(void){
display_line[3][0]=' ';
    display_line[3][1]=' ';
    display_line[3][2]=' ';
    display_line[3][3]=' ';
    display_line[3][4]=' ';
    display_line[3][5]=' ';
    display_line[3][6]=' ';
    display_line[3][7]=' ';
    display_line[3][8]=' ';
    display_line[3][9]=' ';
    display_line[3][10]=' ';
}
void display_ADC_left_detect(void){
      display_line[0][0]=BDC_value[0];
      display_line[0][1]=BDC_value[1];
      display_line[0][2]=BDC_value[2];
      display_line[0][3]=BDC_value[3];
      display_line[0][4]=' ';
      display_line[0][5]=' ';
}
void display_ADC_right_detect(void){
      display_line[0][4]=' ';
      display_line[0][5]=' ';
      display_line[0][6]=BDC_value[0];
      display_line[0][7]=BDC_value[1];
      display_line[0][8]=BDC_value[2];
      display_line[0][9]=BDC_value[3];
}