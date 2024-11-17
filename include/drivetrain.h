// include/drivetrain.h

#pragma once
#include "robot_config.h"

class Drivetrain {
public:
    Drivetrain();
    void driveControl();
    void autonomousDrive(int distance, int speed);
    void autonomousTurn(int degrees, int speed, bool turnRight);
private:
    std::vector<pros::Motor> leftMotors;
    std::vector<pros::Motor> rightMotors;
};