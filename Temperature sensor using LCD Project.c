/*
 * Temperature_sensor_using_LCD_Project.c
 *
 * Created: 9/9/2022 7:39:58 PM
 *  Author: Ahmed Sami
 */ 


#include <avr/io.h>
#include "ADC_driver.h"
#include "LCD.h"
char read_val;
unsigned short temperature;
int main(void)
{
	LCD_vInit();
	ADC_vinit();
	LCD_vSend_string("Temperature=");
    while(1)
    {
        temperature = (ADC_u16Read()*0.25);
		if(temperature < 10)
		{
			LCD_movecursor(1,13);
			LCD_vSend_char(0x30);
			LCD_vSend_char(temperature+48);
			LCD_vSend_char(0xDF);
			LCD_vSend_char('c');
		}
		else if(temperature < 100)
		{
			LCD_movecursor(1,13);
			LCD_vSend_char((temperature/10)+48);
			LCD_vSend_char((temperature%10)+48);
			LCD_vSend_char(0xDF);
			LCD_vSend_char('c');
		}
		else
		{
			
		}
    }
}