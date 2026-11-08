#include "../data.h"
#include "config.h"
#include <Arduino.h>
#include <esp_now.h>

void initialise_Inputs(){
    pinMode(POT1_SW, INPUT_PULLUP);
    pinMode(POT2_SW, INPUT_PULLUP);

    pinMode(POT1_X_YAW, INPUT);
    pinMode(POT1_Y_THROTTLE, INPUT);
    pinMode(POT2_X_ROLL, INPUT);
    pinMode(POT2_Y_PITCH, INPUT);
}

void readJoystick(joystickControls &joystick_data){
    joystick_data.jsYaw = map( analogRead(POT1_X_YAW), 0, 4095, 1000, 2000 );
    joystick_data.jsThrottle = map( analogRead(POT1_Y_THROTTLE), 0, 4095, 1000, 2000 );
    joystick_data.jsRoll = map( analogRead(POT2_X_ROLL), 0, 4095, 1000, 2000 );
    joystick_data.jsPitch = map( analogRead(POT2_Y_PITCH)0, 4095, 1000, 2000 );
}