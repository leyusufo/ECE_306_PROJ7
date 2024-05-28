//******************************************************************************
//
//  Description: This file contains the Function prototypes
//
//  Jim Carlson
//  Aug 2013
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//******************************************************************************
// Functions

// Function Prototype for main
void main(void);

// Initialization
void Init_Conditions(void);

// Interrupts
void enable_interrupts(void);
__interrupt void Timer0_B0_ISR(void);
__interrupt void TIMER0_B1_ISR(void);
__interrupt void Timer1_B0_ISR(void);
__interrupt void TIMER1_B1_ISR(void);
__interrupt void Timer2_B0_ISR(void);
__interrupt void TIMER2_B1_ISR(void);
__interrupt void Timer3_B0_ISR(void);
__interrupt void TIMER3_B1_ISR(void);
__interrupt void switchP4_interrupt(void);
__interrupt void switchP2_interrupt(void);
__interrupt void ADC_ISR(void);

// Analog to Digital Converter ADC
void Init_ADC(void);
void Black_Line_Detect(unsigned int value1, unsigned int value2);
void dir_movement(void);
void ADC_readings(void);
void new_average_ADC(void);          //checks if there is a new average of ADC readings
int ADC_movement(void);

//digital to analog converter DAC
void Init_REF(void);
void Init_DAC(void);
void set_DAC_1200(void);             //sets the DAC to 2000 incrementing decrementing by 100 with timer

// Clocks
void Init_Clocks(void);

// LED Configurations
void Init_LEDs(void);
void IR_LED_control(char selection);
void Backlite_control(char selection);
void Red_LED_Off(void);
void Red_LED_On(void);
void GRN_LED_Off(void);
void GRN_LED_On(void);

// LCD
void Display_Process(void);
void Display_Update(char p_L1,char p_L2,char p_L3,char p_L4);
void enable_display_update(void);
void update_string(char *string_data, int string);
void Init_LCD(void);
void lcd_clear(void);
void lcd_putc(char c);
void lcd_puts(char *s);

void lcd_power_on(void);
void lcd_write_line1(void);
void lcd_write_line2(void);
//void lcd_draw_time_page(void);
//void lcd_power_off(void);
void lcd_enter_sleep(void);
void lcd_exit_sleep(void);
//void lcd_write(unsigned char c);
//void out_lcd(unsigned char c);

void Write_LCD_Ins(char instruction);
void Write_LCD_Data(char data);
void ClrDisplay(void);
void ClrDisplay_Buffer_0(void);
void ClrDisplay_Buffer_1(void);
void ClrDisplay_Buffer_2(void);
void ClrDisplay_Buffer_3(void);

void SetPostion(char pos);
void DisplayOnOff(char data);
void lcd_BIG_mid(void);
void lcd_4line(void);
void lcd_out(char *s, char line, char position);
void lcd_rotate(char view);

//void lcd_write(char data, char command);
void lcd_write(unsigned char c);
void lcd_write_line1(void);
void lcd_write_line2(void);
void lcd_write_line3(void);

void lcd_command( char data);
void LCD_test(void);
void LCD_iot_meassage_print(int nema_index);

// Menu
void Menu_Process(void);

// Ports
void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(void);
void Init_Port4(void);
void Init_Port5(void);
void Init_Port6(void);

// SPI
void Init_SPI_B1(void);
void SPI_B1_write(char byte);
void spi_rs_data(void);
void spi_rs_command(void);
void spi_LCD_idle(void);
void spi_LCD_active(void);
void SPI_test(void);
void WriteIns(char instruction);
void WriteData(char data);

// Switches
void Init_Switches(void);
void switch_control(void);
void enable_switch_SW1(void);
void enable_switch_SW2(void);
void disable_switch_SW1(void);
void disable_switch_SW2(void);
void Switches_Process(void);
void Init_Switch(void);
void Switch_Process(void);
void Switch1_Process(void);
void Switch2_Process(void);
void menu_act(void);
void menu_select(void);


// Timers
void Init_Timers(void);
void Init_Timer_B0(void);
void Init_Timer_B1(void);
void Init_Timer_B2(void);
void Init_Timer_B3(void);

void usleep(unsigned int usec);
void usleep10(unsigned int usec);
void five_msec_sleep(unsigned int msec);
void measure_delay(void);
void out_control_words(void);

//*motors
void Init_Motors(void);
void Motors_Off(void);
void Forward_Motors_On(void);
void Reverse_Motors_On(void);
void Forward_Motors_Off(void);
void Reverse_Motors_Off(void);
void Forward_Right_Motor_On(void);
void Forward_Right_motor_Off(void);
void Forward_Left_Motor_On(void);
void Forward_Left_Motor_Off(void);
void Reverse_Right_Motor_On(void);
void Reverse_Right_motor_Off(void);
void Reverse_Left_Motor_On(void);
void Reverse_Left_Motor_Off(void);
void black_line_found(void);         //checks if the black line has been found and stops the car
void wheel_Safety_Check(void);       //checks for wheel safety
   

//convert hex to ascii
void HEXtoBCD(unsigned int value);

//display messages
void blackLineDetected(void);
void message_left(void);
void message_right(void);
void clear_line3_display(void);
void display_ADC_left_detect(void);
void display_ADC_right_detect(void);