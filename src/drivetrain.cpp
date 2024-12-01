// src/drivetrain.cpp

#include "drivetrain.h"

/**
Tank Drive Setup

Drivetrain::Drivetrain() 
    : leftMotors{pros::Motor(1), pros::Motor(2), pros::Motor(3)},
      rightMotors{pros::Motor(-4), pros::Motor(-5), pros::Motor(-6)} {
    for (auto& motor : rightMotors) {
        motor.set_reversed(true); // Reverse right motors for tank drive
    }
}

void Drivetrain::driveControl() {
    int left = -master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int right = -master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    // Setting Motor Speeds
    for (auto& motor : leftMotors) motor.move(left);
    for (auto& motor : rightMotors) motor.move(right);
}

void Drivetrain::autonomousDrive(int distance, int speed) {
    // Use LemLib or direct motor commands for a distance-based drive
    for (auto& motor : leftMotors) motor.move_relative(distance, speed);
    for (auto& motor : rightMotors) motor.move_relative(distance, speed);
}

void Drivetrain::autonomousTurn(int degrees, int speed, bool turnRight) {
    // Calculate the wheel rotation distance required for the turn
    // This depends on your robot's turning radius and wheel circumference
    double wheelBaseWidth = 24;   // Distance between left and right wheels in inches
    double wheelDiameter = 3.25;  // Diameter of wheels in inches
    double wheelCircumference = wheelDiameter * 3.14159;

    // Calculate arc length for the turn
    double turnCircumference = wheelBaseWidth * 3.14159; // Full rotation circumference
    double arcLength = (degrees / 360.0) * turnCircumference;

    // Convert arc length to motor rotations
    double rotations = arcLength / wheelCircumference;
    double motorDegrees = rotations * 360.0;

    if (turnRight) {
        // Right turn: left motors forward, right motors backward
        for (auto& motor : leftMotors) motor.move_relative(motorDegrees, speed);
        for (auto& motor : rightMotors) motor.move_relative(-motorDegrees, speed);
    } else {
        // Left turn: left motors backward, right motors forward
        for (auto& motor : leftMotors) motor.move_relative(-motorDegrees, speed);
        for (auto& motor : rightMotors) motor.move_relative(motorDegrees, speed);
    }
}
*/

/**
Arcade Drive Setup

Drivetrain::Drivetrain() 
    : leftMotors{pros::Motor(1), pros::Motor(2), pros::Motor(3)},
      rightMotors{pros::Motor(-4), pros::Motor(-5), pros::Motor(-6)}{
}

void Drivetrain::driveControl() {
    // Get joystick inputs for arcade control
    int forward = -master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = -master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    
    // Calculate motor speeds for left and right sides using arcade drive
    int leftSpeed = forward + turn;  // Left side of bot
    int rightSpeed = forward - turn; // Right side of bot

    // Setting Motor Speeds
    for (auto& motor : leftMotors) motor.move(leftSpeed);
    for (auto& motor : rightMotors) motor.move(rightSpeed);
}

void Drivetrain::autonomousDrive(int distance, int speed) {
    // Use LemLib or direct motor commands for a distance-based drive
    for (auto& motor : leftMotors) motor.move_relative(distance, speed);
    for (auto& motor : rightMotors) motor.move_relative(distance, speed);
}

void Drivetrain::autonomousTurn(int degrees, int speed, bool turnRight) {
    // Calculate the wheel rotation distance required for the turn
    // This depends on your robot's turning radius and wheel circumference
    double wheelBaseWidth = 24;   // Distance between left and right wheels in inches
    double wheelDiameter = 3.25;  // Diameter of wheels in inches
    double wheelCircumference = wheelDiameter * 3.14159;

    // Calculate arc length for the turn
    double turnCircumference = wheelBaseWidth * 3.14159; // Full rotation circumference
    double arcLength = (degrees / 360.0) * turnCircumference;

    // Convert arc length to motor rotations
    double rotations = arcLength / wheelCircumference;
    double motorDegrees = rotations * 360.0;

    if (turnRight) {
        // Right turn: left motors forward, right motors backward
        for (auto& motor : leftMotors) motor.move_relative(motorDegrees, speed);
        for (auto& motor : rightMotors) motor.move_relative(-motorDegrees, speed);
    } else {
        // Left turn: left motors backward, right motors forward
        for (auto& motor : leftMotors) motor.move_relative(-motorDegrees, speed);
        for (auto& motor : rightMotors) motor.move_relative(motorDegrees, speed);
    }
}
*/