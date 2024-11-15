// src/pneumatics.cpp

#include "pneumatics.h"

Pneumatics::Pneumatics()
    : clampPiston1(PNEUMATIC_PORT_1), clampPiston2(PNEUMATIC_PORT_2), clampOpen(false) {}

void Pneumatics::controlClamp() {
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
        clampOpen = true;
    } else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
        clampOpen = false;
    }
    clampPiston1.set_value(clampOpen);
    clampPiston2.set_value(clampOpen);
}
