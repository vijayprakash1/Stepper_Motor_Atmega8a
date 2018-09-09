/*
 * motor.c
 *
 * Created: 23-08-2018 3.03.33 PM
 *  Author: Vijay
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "delay.h"
#define MotorA PORTD6
#define MotorB PORTD7
#define MotorA1 PORTB0
#define MotorB1 PORTB1
void motor_pe(int DLY)
{
	PORTD&= ~(1<<MotorA);
	PORTD&= ~(1<<MotorB);
	delay(DLY);
	PORTD&= ~(1<<MotorB);
	PORTD|= (1<<MotorA);
	delay(DLY);
	PORTD|= (1<<MotorA);
	PORTD|= (1<<MotorB);
	delay(DLY);
	PORTD&= ~(1<<MotorA);
	PORTD|= (1<<MotorB);
	delay(DLY);

}

void motor_core(int DLY)
{
	PORTD&= ~(1<<MotorA);
	PORTD&= ~(1<<MotorB);
	PORTD&= ~(1<<MotorA1);
	PORTD&= ~(1<<MotorB1);
	delay(DLY);
	PORTD&= ~(1<<MotorB);
	PORTD|= (1<<MotorA);
	PORTD&= ~(1<<MotorB1);
	PORTD|= (1<<MotorA1);
	delay(DLY);
	PORTD|= (1<<MotorA);
	PORTD|= (1<<MotorB);
	PORTD|= (1<<MotorA1);
	PORTD|= (1<<MotorB1);
	delay(DLY);
	PORTD&= ~(1<<MotorA);
	PORTD|= (1<<MotorB);
	PORTD&= ~(1<<MotorA1);
	PORTD|= (1<<MotorB1);
	delay(DLY);

}