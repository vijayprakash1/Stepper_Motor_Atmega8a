/*
 * Swachh_3.0_Core_Feb_1st_order.c
 *
 * Created: 28-02-2018 3.24.56 PM
 * Author : Vijay
  @brief     This file provides firmware functions of Core unit which manage the following
  *          functionalities of the GPIO peripheral:
  *          + Initializing and Configuration of GPIO
  *          + Function Definition for Stepper Motors (Top & Bottom Sheet Motor , Core Layer Motor)
  *          + Different types of Sensor Reads(Limit Switch, Reed Switch )
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
#define GLUEP PORTD3
#define GLUEC PORTD2
#define CUTT PORTD4
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
	PORTD|= (1<<CUTT);
	delay(50);
	PORTD&= ~(1<<CUTT);
	delay(20);
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
					   PORTD|= (1<<GLUEP);
					   motor_pe(DLY); 
				   }
				   LIMIT = (PINC& (1<<Lswitch));  //   Check the position of Limit  Switch
				   while (LIMIT == 0)
				   {
					  motor_core(DLY);
					  PORTD|= (1<<GLUEC);
					  LIMIT = (PINC& (1<<Lswitch));
					}
					PORTD&= ~(1<<GLUEC);
					PORTD&= ~(1<<GLUEP);
					PORTD|= (1<<CUTT);
					delay(50);
					PORTD&= ~(1<<CUTT);
					delay(20);
				   }
			}
		}
	}
