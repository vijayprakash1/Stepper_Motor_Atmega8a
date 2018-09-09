# Stepper_Motor_Atmega8a
This Project will cover how to control high torque i.e. Nema 24 and above series stepper motor with help of Atmega8A
In this file you will learn how to control the RPM of the Stepper motor and how you can stop with help of any sensors.
Formula I am Using to control RMP of the motor is 

                       f = ((rpm*microstep)/4*60)
                       t(delay b/w each pulse) = ((1000000)/(4*f))
                       
                       
                       
