#pragma once

struct mpuData{
    float rollSpeed;//x, y, and z axes
    float pitchSpeed;
    float yawSpeed;

    float accelX;
    float accelY;
    float accelZ;
};

//js for joystick
struct joystickControls{
    float jsYaw;
    float jsThrottle;
    float jsRoll;
    float jsPitch;
};

#endif