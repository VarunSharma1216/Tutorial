#include "main.h"
pros::ADIGyro gyro('B',0.91')
void setDrive (int left, int right){
  driveLeftBack = left;
  driveLeftFront = left;
  driveRightBack = right;
  driveRightFront = right;
}

void resetDriveEncoders(){
  driveLeftBack.tare_position();
  driveLeftFront.tare_position();
  driveRightBack.tare_position();
  driveRightFront.tare_position();


}

double averageDriveEncoderValue(){
  return (fabs(driveLeftFront.getposition()+fabs(driveLeftBack.getposition())
  +fabs(driveRightFront.getposition())+fabs(driveRightBack.getposition()))/4;
}
void setDriveMotors(){
  int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  if (abs(leftJoystick) < 10){
    leftJoystick = 0;
  }
  if (abs(rightJoystick) < 10){
    rightJoystick = 0;
  }
  setDrive(leftJoystick, rightJoystick);
}


void translate(int units, int voltage){
  int direction = abs(units)/units
  resetDriveEncoders();
  gyro.reset();
  while(averageDriveEncoderValue()<abs(units)){
    setdrive(voltage * direction+gyro.get_value(),voltage * direction-gyro.get_value());
    pros::delay(10);
  }
  setDrive(-10*direction,-10*direction);
  pros::delay(50);
  setDrive(0,0);
}
void rotate (int degrees, int voltage){
  int direction = abs(degrees)/degrees;
  gyro.reset();
  setDrive(-voltage*direction,voltage*direction);
  while (fabs(gyro.get_value())<abs(degrees*10)-50){
    pros::delay(10);
  }
  pros::delay(100);
  if(fabs(gyro.get_value())>abs(degrees*10)){
    setDrive(voltage*0.5*direction,-voltage*0.5*direction);
    while (fabs(gyro.get_value())>abs(degrees*10)){
      pros::delay(10);
    }
  }
  else if (fabs(gyro.get_value())<abs(degrees*10){
    setDrive(-voltage*0.5*direction,voltage*0.5*direction);
    while (fabs(gyro.get_value())<abs(degrees*10)){
      pros::delay(10);
  }
  setdrive(0,0);

}
