#include "data.h"
#include "config.h"
#include "components.h"

#include <Adafruit_MPU6050.h>
#include <Arduino.h>
#include <Adafruit_Sensors.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
mpuData mpu_data;
sensors_event_t accel, gyro, temp;

float throttle = 130.0;
float yaw = 0.0;

const int PWM_FREQUENCY = 20000, PWM_RES = 8;

void setup(){
    Serial.begin(115200);

    Serial.println("STRATOSPHERE!!");

    if(!initialiseMPU6050()){
        Serial.println("MPU did not load");
    }
    else{
        Serial.println("MPU6050 setup");
    }

    initialiseMotors();

    Wifi.mode(WIFI_STA);
    if(esp_now-init() != ESP_OK){
        Serial.println("ESP-NOW initialisation failed.");
    }

    esp_now_register_recv_cb(onDataReceive);
    Serial.println("Drone initialised");
    
    stabiliseMotors(mpu_data);
}

void loop(){
    long currentMicros = micros();
    const long LOOP_US = 5000;

    readMPU6050();
}