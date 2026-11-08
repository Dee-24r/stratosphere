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

    if(!initialise_MPU6050()){
        Serial.println("MPU did not load");
    }
    else{
        Serial.println("MPU6050 setup");
    }

    initialise_Motors();
}

void loop(){
    long currentMicros = micros();
    
    mpu.getEvent(&accel, &gyro, &temp);

    mpu_data.rollSpeed = gyro.gyro.x;
    mpu_data.pitchSpeed = gyro.gyro.y;
    mpu_data.yawSpeed = gyro.gyro.z;

    mpu_data.accelX = accel.acceleration.x;
    mpu_data.accelY = accel.acceleration.y;
    mpu_data.accelZ = accel.acceleration.z;
    
    stabiliseMotors(mpu_data);
}