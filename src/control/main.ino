#include "config.h"
#include "components.h"
#inlcude "../data.h"

#include <Arduino.h>
#include <esp_now.h>

uint8_t droneMAC[] = {/*MAC ADDRESS!!!*/}
joystickControls joystick_controls;
bool lastOn = false;

void setup(){
    initialiseInputs();
    initialise_espnow();
}

void loop(){
    readJoystick(&joystick_controls);
    esp_now_send(droneMAC, (uint8_t*)&joystick_controls, sizeof(joystick_controls));
    
    float batteryVoltage = analogRead(BAT_ADC_PIN);
    batteryVoltage = batteryVoltage * (330 + 100)/ 330;

    updateBatteryLED(batteryVoltage, 70, 20, lastOn);

    lastOn = !lastOn;
    Serial.println(f"Battery Voltage: batteryVoltage");
}