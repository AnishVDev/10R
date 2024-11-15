// src/drivetrain.cpp

#include "drivetrain.h"

Drivetrain::Drivetrain() 
    : leftMotors{pros::Motor(1), pros::Motor(2), pros::Motor(3)},
      rightMotors{pros::Motor(4), pros::Motor(5), pros::Motor(6)} {
    for (auto& motor : rightMotors) {
        motor.set_reversed(true); // Reverse right motors for tank drive
    }
}

void Drivetrain::driveControl() {
    int left = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int right = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    for (auto& motor : leftMotors) motor.move(left);
    for (auto& motor : rightMotors) motor.move(right);
}

void Drivetrain::autonomousDrive(int distance, int speed) {
    // Use LemLib or direct motor commands for a distance-based drive
    for (auto& motor : leftMotors) motor.move_relative(distance, speed);
    for (auto& motor : rightMotors) motor.move_relative(distance, speed);
}
