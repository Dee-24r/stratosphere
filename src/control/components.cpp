#include "../data.h"
#include "config.h"
#include "components.h"
#include <Arduino.h>
#include <esp_now.h>

#include <Adafruit_MPU6050.h>

void initialiseInputs(){
    pinMode(POT1_SW, INPUT_PULLUP);
    pinMode(POT2_SW, INPUT_PULLUP);
    pinMode(BAT_ADC_PIN, INPUT);
    pinMode(BAT_LED, OUTPUT);

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

void initialise_espnow(){
    Wifi.mode(WIFI.STA);
    if(esp_now_init() != ESP_OK){
        Serial.println("ESP-NOW INITIALISATION FAILED");
        return;
    }

    esp_now_peer_info_t droneInfo = {};//idk
    memcpy(droneInfo.peer_addr, &droneMAC, 6);

    droneInfo.channel = 0;
    droneInfo.encrypt = false;

    if(esp_now_add_peer(&droneInfo) != ESP_OK){
        Serial.println("couldn't add drone.")
        return;
    }

    Serial.println("Connected");
}

void updateBatteryLED(float batteryVoltage, float lowBar, float mediumBar, bool lastOn){
    
    if (batteryVoltage >= mediumBar)
        digitalWrite(BAT_LED, HIGH);
    else if(batteryVoltage >= lowBar){
        if(lastOn) == 1 {
            digitalWrite(BAT_LED, LOW);
        }
        else{
            digitalWrite(BAT_LED, HIGH);
        }
    }
    else
        digitalWrite(BAT_LED, LOW);
}