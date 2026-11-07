#include "config.h"
#include "components.h"
#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>


Adafruit_MPU6050 mpu;

void stabiliseMotors(const mpuData)

bool initialise_MPU6050(){
    Wire.beginTransmission(MPU6050_ADDR);
    Wire.write(0x68);
    Wire.write(0x00);

    if (Wire.endTransmission != 0)
        return false;
    

    Wire.beginTransmission(MPU6050_ADDR);
    Wire.write(0x1B);
    Wire.write(0x08);
    Wire.endTransmission();

    Wire.beginTransmission(MPU6050_ADDR);
    Wire.write(0x1A);
    Wire.write(0x03);
    Wire.endTransmission();
      
    return true;
}

bool readGyro(mpuData &mpu_data){
    Wire.beginTransmission(MPU6050_ADDR);
    Wire.write(0x43);
    Wire.endTransmission(false);
}

bool initialise_Motors(){
    pinMode(MOTOR_1, OUTPUT);
    pinMode(MOTOR_2, OUTPUT);
    pinMode(MOTOR_3, OUTPUT);
    pinMode(MOTOR_4, OUTPUT);

    digitalWrite(MOTOR_1, LOW);
    digitalWrite(MOTOR_2, LOW);
    digitalWrite(MOTOR_3, LOW);
    digitalWrite(MOTOR_4, LOW);

}

void readMPUData(mpuData &mpu_data);











bool initialiseMotors(){

}

begin(uint8_t i2c_address, TwoWire *wire, int32_t sensor_id)