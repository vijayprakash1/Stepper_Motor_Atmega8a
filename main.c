/*

 * Created: 28-02-2018 3.24.56 PM
 * Author : Vijay
  @brief     This file provides firmware functions of Core unit which manage the following
  *          functionalities of the GPIO peripheral:
  *          + Initializing and Configuration of GPIO
  *          + Function Definition for Stepper Motors 
  *          + Different types of Sensor Reads(Limit Switch, Reed Switch ) you can use any other sensors as per your need
  *          + Pin Configuration as following:
  *          + Top & Bottom Sheet Motor(PORTD 6,7)
  *          + Core Layer Motor (PORTB 0,1)
  *          + Reed Switch (REED C2)
  *          + Reed Sensor (BUTTON C0)
             Stepper motor frequency formula        f =  (rmp * number of step(800) / 60);   
  */ 

#include <avr/io.h>
#include "delay.h"
#include "motor.h"
#define Lswitch PORTC0
#define Rswitch PORTC2
unsigned int DLY = 20;
unsigned REED,LIMIT;
int i;

int main(void)
{
    DDRB = 0xFF;
    DDRC = 0x00;
	DDRD = 0xFF;
	
	LIMIT = (PINC& (1<<Lswitch));  //   Check the position of Limit  Switch
	while (LIMIT == 0)
	{
	motor_pe(DLY);	
	LIMIT = (PINC& (1<<Lswitch)); 
	}
	    
			while (1)
			{
			   REED = (PINC& (1<<Rswitch));	
			   if (REED != 0)
			   {
				   delay(2);
				   if (REED != 0)
				   {
				   for(i=0;i<=400;i++)
				   {
					  
					   motor_pe(DLY); 
				   }
				   LIMIT = (PINC& (1<<Lswitch));  //   Check the position of Limit  Switch
				   while (LIMIT == 0)
				   {
					  motor_core(DLY);
					 
					  LIMIT = (PINC& (1<<Lswitch));
					}
					
				   }
			}
		}
	}
