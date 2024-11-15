// include/robot_config.h

#pragma once
#include "pros/adi.hpp"
#include "pros/motors.hpp"

// Drivetrain motor ports
#define LEFT_MOTOR_PORTS {1, 2, 3}
#define RIGHT_MOTOR_PORTS {4, 5, 6}

// Intake motor port
#define INTAKE_MOTOR_PORT 7

// Pneumatics ports
#define PNEUMATIC_PORT_1 1
#define PNEUMATIC_PORT_2 2

// Controller
extern pros::Controller master;
