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

void autonomous() {
    drivetrain.autonomousDrive(1000, 100); // Example autonomous movement
    intake.controlIntake(); // Add further actions as needed
}

void opcontrol() {
    while (true) {
        drivetrain.driveControl();
        intake.controlIntake();
        pneumatics.controlClamp();
        pros::delay(20);
    }
}
