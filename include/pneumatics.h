// include/pneumatics.h

#pragma once
#include "robot_config.h"
#include "pros/adi.hpp"

class Pneumatics {
public:
    Pneumatics();
    void controlClamp();
    void setClampState(bool open);      // Explicitly set clamp state
    bool isClampOpen() const;           // Get current clamp state
private:
    pros::ADIDigitalOut clampPiston1;
//  pros::ADIDigitalOut clampPiston2;
    bool clampOpen;
};