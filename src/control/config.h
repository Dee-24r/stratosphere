#pragma once

#define BAT_ADC_PIN 1
#define BAT_LED 18

#define POT1_X_YAW 4 //potentiometer
#define POT1_Y_THROTTLE 5

//just my thoughts, pitch and roll tgthr
#define POT2_X_ROLL 6
#define POT2_Y_PITCH 7

#define POT1_SW 16
#define POT2_SW 17

#define RADIANS_TO_DEG = 57.2958;
#define const float ALPHA = 0.98;
#define PWM_FREQUENCY 20000
#define PWM_RES 8
#define MPU6050 0x68