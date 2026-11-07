#include "data.h"
#include "config.h"
#include "components.h"

#include <Adafruit_MPU6050.h>
#include <Arduino.h>
#include <Adafruit_Sensors.h>
#include <Wire.h>

mpuData mpu_data;
sensors_event_t accel, gyro, temp;

void setup(){
    Serial.begin(115200);

    Serial.println("STRATOSPHERE!!");

    if(!mpu.begin()){
        Serial.println("MPU did not load");
    }
    else{
        Serial.println("MPU6050 setup");
    }

    mpu.setHighPassFilter(MPU6050_HIGHPASS);
    mpu.setMotionDetectionThreshold(1);

    mpu.setAccelerometerRange(mpu6050_accel_range_t MPU6050_RANGE_16_G);
    mpu.setGyroRange(mpu6050_gyro_range_t MPU6050_RANGE_2000_DEG);
}

void loop(){
    mpu.getEvent(&accel, &gyro, &temp);

    mpu_data.rollSpeed = gyro.gyro.x;
    mpu_data.pitchSpeed = gyro.gyro.y;
    mpu_data.yawSpeed = gyro.gyro.z;

    mpu_data.accelX = accel.acceleration.x;
    mpu_data.accelY = accel.acceleration.y;
    mpu_data.accelZ = accel.acceleration.z;
    
    delay(4);
}