#include "../data.h"
#include "config.h"
#include <Arduino.h>
#include <esp_now.h>

void initialiseInputs();
void readJoystick();
void initialise_espnow();
void updateBatteryLED(float batteryVoltage, float lowBar, float mediumBar, bool lastOn)