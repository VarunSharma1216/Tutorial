#include "main.h"
void setLift(int power){
  lift = power;
}
void setLiftMotors(){
   int intakePower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2 );
   setLift(liftPower);
 }
