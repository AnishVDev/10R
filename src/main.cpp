/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * \copyright Copyright (c) 2017-2023, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * pros upload in Integrated Terminal to upload code to VEX Brain
 */

#include "main.h"
#include "drivetrain.h"
#include "intake.h"
#include "pneumatics.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
Drivetrain drivetrain;
Intake intake;
Pneumatics pneumatics;

void initialize() {
    // Initialization code here
}

/**
Right Side Auton
*/
void autonomous() {
    drivetrain.autonomousDrive(2000, 100);
    pros::delay(1000);
    pneumatics.setClampState(true);
    pros::delay(500);        // Delay to ensure the clamp has time  to actuate
    intake.setIntake(130);          // Turn intake on
    pros::delay(500);        // Run intake for 0.5 seconds
    intake.stopIntake();                  // Stop the intake
    pros::delay(500);
    pneumatics.setClampState(false);
    pros::delay(100);
    drivetrain.autonomousDrive(-1800, 100);
    pros::delay(900);
    drivetrain.autonomousTurn(90, 100, true);  // Turn -90 degrees at a speed of 100 to the right
    pros::delay(2000);                                     // Wait for 2 seconds to complete the turn
    drivetrain.autonomousDrive(-1800, 100);
    pros::delay(900);
    drivetrain.autonomousDrive(1800, 100);
    pros::delay(900);
    drivetrain.autonomousDrive(-1800, 100);
    pros::delay(900);
    drivetrain.autonomousDrive(1800, 100);
    pros::delay(900);
    drivetrain.autonomousDrive(-1800, 100);
}

void opcontrol() {
    while (true) {
        drivetrain.driveControl();
        intake.controlIntake();
        pneumatics.controlClamp();
        pros::delay(20);
    }
}