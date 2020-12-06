#include "main.h"

void opcontrol() {
	while(true){
		setDriveMotors();
		setIntakeMotors();
		setLiftMotor();
		setAnglerMotor();
		pros::delay(10);
	}
