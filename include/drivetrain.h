// include/drivetrain.h

#pragma once
#include "robot_config.h"

class Drivetrain {
public:
    Drivetrain();
    void driveControl();
    void autonomousDrive(int distance, int speed);
private:
    std::vector<pros::Motor> leftMotors;
    std::vector<pros::Motor> rightMotors;
};
