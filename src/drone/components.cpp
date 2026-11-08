#include "config.h"
#include "components.h"
#include "../data.h"
#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Wifi.h>


void initialise_Motors(){
    ledcAttachChannel(MOTOR_1_PIN, PWM_FREQUENCY, PWM_RES, 0);
    ledcAttachChannel(MOTOR_2_PIN, PWM_FREQUENCY, PWM_RES, 1);
    ledcAttachChannel(MOTOR_3_PIN, PWM_FREQUENCY, PWM_RES, 2);
    ledcAttachChannel(MOTOR_4_PIN, PWM_FREQUENCY, PWM_RES, 3)
}

bool initialise_MPU6050(){
    if(!Wire.begin(I2C_SDA, I2C_SCL)){
        return false;
    }

    if(!mpu.begin(MPU6050_ADDRC, &Wire)){
        return false;
    }

    mpu.setHighPassFilter(MPU6050_HIGHPASS_5_HZ);
    mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
    mpu.setGyroRange(MPU6050_RANGE_2000_DEG);

    return true;
}


void stabiliseMotors(const mpuData &mpu_data){
    long lastTime = 0;
    if(lastTime == 0)
        lastTime = micros();

    float anglePitch = 0.0, angleRoll = 0.0;
    float targetPitch = 0.0, targetRoll = 0.0;
    float errorRoll, errorPitch;
    float ALPHA = 0.98; //will do more research on which value is beter, but this is fo merging the accelerometer and gyro values to use for the thi

    long currentTime = micros();
    float time-difference = (micros() - lastTime) / 1000000 //this is seconds

    mpu_data.rollSpeed = mpu_data.rollSpeed * 57.2958;
    mpu_data.pitchSpeed = mpu_data.pitchSpeed * 57.2958;//radian to degrees /secodn

    mpu_data.pitchSpeed = mpu_data.
    float integralRoll = 0.0
    const long loop_time = 5000;


    int motor_1_pwm, motor_2_pwm, motor_3_pwm, motor_4_pwmk;

    //roll = ALPHA * (angleRoll)


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

bool readMPU6050(mpuData &mpu_data){
    Wire.beginTransmission(MPU6050_ADDR);
    Wire.write(0x43);
    Wire.endTransmission(false);
}

