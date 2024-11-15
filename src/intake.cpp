// src/intake.cpp

#include "intake.h"

Intake::Intake() 
    : intakeMotor(INTAKE_MOTOR_PORT),
      intakeRunningForward(false), intakeRunningReverse(false) {}

void Intake::controlIntake() {
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
        intakeRunningForward = !intakeRunningForward;
        intakeRunningReverse = false;
        intakeMotor.move(intakeRunningForward ? 100 : 0);
    } else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
        intakeRunningReverse = !intakeRunningReverse;
        intakeRunningForward = false;
        intakeMotor.move(intakeRunningReverse ? -100 : 0);
    }
}
