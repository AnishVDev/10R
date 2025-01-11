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


   _____         .__       .__  ____   ____________                
  /  _  \   ____ |__| _____|  |_\   \ /   /\______ \   _______  __ 
 /  /_\  \ /    \|  |/  ___/  |  \   Y   /  |    |  \_/ __ \  \/ / 
/    |    \   |  \  |\___ \|   Y  \     /   |    `   \  ___/\   /  
\____|__  /___|  /__/____  >___|  /\___/   /_______  /\___  >\_/   
        \/     \/        \/     \/                 \/     \/       
 ___________ __________ 
/_   \   _  \\______   \
 |   /  /_\  \|       _/
 |   \  \_/   \    |   \
 |___|\_____  /____|_  /
            \/       \/ 



 * @file main.cpp
 * @brief This file contains the main code for the robot's operation.
 *
 * Robot Controller:
 *
 * Tank Drive
 * Left Joystick (Vertical): Controls left side of drivetrain (forward/backward).
 * Right Joystick (Vertical): Controls right side of drivetrain (forward/backward).
 *
 * Arcade Drive
 * Left Joystick (Vertical): Controls movement of the drivetrain (forward/backward).
 * Right Joystick (Horizontal): Controls rotation of the drivetrain (left/right).
 *
 * Controller Settings:
 * R1: Press once to start the intake moving forward. Press again to stop the intake (if it's already running forward).
 * R2: Press once to start the intake moving in reverse. Press again to stop the intake (if it's already running in reverse).
 * L1: Opens the clamp by activating the pistons.
 * L2: Closes the clamp by deactivating the pistons.
 *
 * Motor Settings:
 * Motor Ports: 1-6 (left ports: 1, 2, and 3; right ports: 4, 5, and 6)
 * Intake Port: Port 7
 * Pneumatics (Clamp Pistons): ADI Port A
 * Controller: USB Ports to wirelessly connect to VEX Brain
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
    pros::delay(1000);        // Delay to ensure the clamp has time  to actuate
    intake.setIntake(130);          // Turn intake on
    pros::delay(500);        // Run intake for 0.5 seconds
    intake.stopIntake();                  // Stop the intake
    pros::delay(500);
    drivetrain.autonomousDrive(2000, 100);
    pros::delay(2000);
    drivetrain.autonomousTurn(200, 110, true);  // Turn 125 degrees at a speed of 100 to the right
/**
    pneumatics.setClampState(false);
    pros::delay(100);
    drivetrain.autonomousDrive(-1800, 100);
    pros::delay(900);
    drivetrain.autonomousTurn(125, 100, true);  // Turn 125 degrees at a speed of 100 to the right
    pros::delay(2000);                                     // Wait for 2 seconds to complete the turn
    drivetrain.autonomousDrive(-1800, 100);
    pros::delay(900);
    drivetrain.autonomousDrive(1800, 100);
    pros::delay(900);
    drivetrain.autonomousDrive(-1900, 100);
    pros::delay(900);
    drivetrain.autonomousDrive(1800, 100);
    pros::delay(900);
    drivetrain.autonomousDrive(-2000, 100);
*/
}

void opcontrol() {
    while (true) {
        drivetrain.driveControl();
        intake.controlIntake();
        pneumatics.controlClamp();
        pros::delay(20);
    }
}