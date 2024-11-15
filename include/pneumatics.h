// include/pneumatics.h

#pragma once
#include "robot_config.h"

class Pneumatics {
public:
    Pneumatics();
    void controlClamp();
private:
    pros::ADIDigitalOut clampPiston1;
    pros::ADIDigitalOut clampPiston2;
    bool clampOpen;
};
