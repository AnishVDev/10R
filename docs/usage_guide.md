#  `Usage Guide`

## Running the Project

To run the robot, upload the compiled code to your VEX controller using the PROS environment.

### Build the Project
Run `pros build` in your pros integrated terminal to build project and check for errors.

### Upload the Project
Run `pros upload` in your pros integrated terminal to upload your project to your brain via a download cable.

### Features

**Autonomous Navigation:** The robot can navigate using built-in sensors.  
**Manual Control:** Use the joystick to control the robot’s movement with tank drive.  

### Example Usage
Here's a brief example of how to control the robot using the joystick.  


```markdown
void opcontrol() {
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    
    while (true) {
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        
        chassis.tank(leftY, rightY); // Control movement
        
        pros::delay(20);
    }
}
```
