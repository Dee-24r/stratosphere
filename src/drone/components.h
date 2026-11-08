#pragma once

#include "config.h"
#include "../data.h"

void stabiliseMotors(const mpuData mpu_data);
void initialiseMotors();
void initialiseMPU6050();
void readMPU6050(mpuData mpu_data);