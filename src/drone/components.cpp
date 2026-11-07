#include "config.h"
#include "components.h"
#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>


Adafruit_MPU6050 mpu;

bool initialise_MPU6050(){
    if (!mpu.begin())
        return false;
    Serial.println("MPU6050 did not load!");
    
    # mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    return true;
}

bool initialise_Motors(){
    pinMode(MOTOR_1, OUTPUT);
    pinMode(MOTOR_2, OUTPUT);
    pinMode(MOTOR_3, OUTPUT);
    pinMode(MOTOR_4, OUTPUT);
}

void readMPUData(mpuData &mpu_data);











bool initialiseMotors(){

}

begin(uint8_t i2c_address, TwoWire *wire, int32_t sensor_id)