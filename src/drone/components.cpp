#include "config.h"
#include "components.h"
#include "../data.h"
#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Wifi.h>


void initialiseMotors(){
    ledcAttachChannel(MOTOR_1_PIN, PWM_FREQUENCY, PWM_RES, 0);
    ledcAttachChannel(MOTOR_2_PIN, PWM_FREQUENCY, PWM_RES, 1);
    ledcAttachChannel(MOTOR_3_PIN, PWM_FREQUENCY, PWM_RES, 2);
    ledcAttachChannel(MOTOR_4_PIN, PWM_FREQUENCY, PWM_RES, 3)
}

bool initialiseMPU6050(){
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


void stabiliseMotors(const mpuData &mpu_data, const joystickControls &joystick_controls, float change-in-time){
    
    float pitchAngle = 0.0, rollAngle = 0.0;
    bool firstReading = true;

    float rollRate = mpu_data.rollSpeed * RADIANS_TO_DEG;
    float pitchRate = mpu_data.pitchSpeed * RADIANS_TO_DEG;
    float yawRate = reading.yawSpeed * RADIANS_TO_DEG;

    float accelRoll = atan2f(mpu_data.accelY, mpu_data.accelZ) * RADIANS_TO_DEG;
    float accelPitch = atan2f(-mpu_data.accelX, sqrtf(mpu_data.accelY * mpu_data.accelY + mpu_data.accelZ * mpu_data.accelZ)) * RAD_TO_DEG; //this is tan inverse squared (accy, accz)

    if(!firstReading){
        rollAngle = accelRoll;
        pitchAngle = accelPitch;
        firstReading = false;
    }
    else{
        rollAngle = ALPHA * (rollAngle + rollRate * change-in-time) + (1 - alpha) * accelRoll;
        pitchAngle = ALPHA * (pitchAngle + pitchRate * change-in-time) + (1 - ALPHA) * accelPitch;
    }

    float errorRoll = joystick_controls.jsRoll - rollAngle;
    float errorPitch = joystick_controls.jsPitch - pitchAngle;
    float yawError = joystick_controls.jsYaw = yawRate;

    int motor_1_pwm, motor_2_pwm, motor_3_pwm, motor_4_pwm;

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

void readMPU6050(mpuData &mpu_data){
    
    sensors_event_t accel, gyro, temp;
    mpu.getEvent(&accel, &gyro, &temp);

    mpu_data.rollSpeed = gyro.gyro.x;
    mpu_data.pitchSpeed = gyro.gyro.y;
    mpu_data.yawSpeed = gyro.gyro.z;

    mpu_data.accelX = accel.acceleration.x;
    mpu_data.accelY = accel.acceleration.y;
    mpu_data.accelZ = accel.acceleration.z;
    
}

void onDataReceive(const esp_now_recv_info_t *info, joystickControls *data_sent, int len){
    memcpy(&joystick_controls, )
}
