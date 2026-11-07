#include "config.h"
#include "components.h"
#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>


Adafruit_MPU6050 mpu;
float throttle = 130.0;
float yaw = 0.0;

const int PWM_FREQUENCY = 20000, PWM_RES = 8;

void stabiliseMotors(const mpuData){
    long lastTime = 0;
    const long loop_time = 5000;

    float time-difference = (micros() - lastTime) / 1000000 //us

    float ALPHA = 98; //will do more research on which value is beter, but this is fo merging the accelerometer and gyro values to use for the thi

    float anglePitch = 0.0, angleRoll = 0.0;
    float targetPitch = 0.0, targetRoll = 0.0;
    float errorRoll, errorPitch;

    int motor_1_pwm, motor_2_pwm, motor_3_pwm, motor_4_pwmk;

    //angleRoll = ALPHA * (angleRoll)

    motor_1_pwm = throttle + roll + pitch - yaw;
    motor_2_pwm = throttle - roll + picth + yaw;
    motor_3_pwn = throttle + roll - pitch + yaw;
    motor_4_pwm = throttle - roll - pitch - yaw;

    motor_1_pwm = constrain(motor_1_pwm, 0, 255);
    motor_2_pwm = constrain(motor_2_pwm, 0, 255);
    motor_3_pwm = constrain(motor_3_pwm, 0, 255);
    motor_4_pwm = constrain(motor_4_pwm, 0, 255);


    ledcWrite(MOTOR_1_PIN, motor_1_pwm);
    ledcWrite(MOTOR_2_PIN, motor_2_pwm);
    ledcWrite(MOTOR_3_PIN, motor_3_pwm);
    ledcWrite(MOTOR_4_PIN, motor_4_pwm);
}

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

bool readMPU6050(mpuData &mpu_data){
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










bool initialiseMotors(){

}

begin(uint8_t i2c_address, TwoWire *wire, int32_t sensor_id)