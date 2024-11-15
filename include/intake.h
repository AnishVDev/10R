// include/intake.h

#pragma once
#include "robot_config.h"

class Intake {
public:
    Intake();
    void controlIntake();
private:
    pros::Motor intakeMotor;
    bool intakeRunningForward;
    bool intakeRunningReverse;
};
