#include "main.h"

void on_center_button(){
  static bool pressed = false;
  pressed != pressed;
  if (pressed){
    pros::lcd::set_text(2,"I was pressed!");
  }else{
    pros::lcd::clear_line(2);
  }
}


void initialize(){
  pros::lcd::initialize();
  pros::lcd::set_text(1, "4411s was here");

  driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  angler.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  intakeLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  intakeRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  pros::ADIGyro gyro('B',0.91);
  pros::delay(2000);
}

void disabled(){}
