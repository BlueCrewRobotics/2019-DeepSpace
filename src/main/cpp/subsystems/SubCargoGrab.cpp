/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "subsystems/SubCargoGrab.h"

#include "RobotMap.h"
#include "Robot.h"

SubCargoGrab::SubCargoGrab() : frc::Subsystem("SubCargoGrab") {}

void SubCargoGrab::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
//

void SubCargoGrab::Intake(double leftspeed, double rightspeed){
  // This might need to be changed on the final robot
  leftspeed = leftspeed * -1;
	leftIntakeMotor->Set(leftspeed);
  rightIntakeMotor->Set(rightspeed);
}

void SubCargoGrab::Shoot(double leftspeed, double rightspeed){
  // This might need to be changed on the final robot
  leftspeed = leftspeed * -1;
	leftIntakeMotor->Set(leftspeed);
  rightIntakeMotor->Set(rightspeed);
}

void SubCargoGrab::Stop(){
  leftIntakeMotor->Set(0);
  rightIntakeMotor->Set(0);
}

void SubCargoGrab::ClampSet(bool state){
  Robot::m_subPCM.ptr_ClampSolenoid->Set(state);
}

void SubCargoGrab::SetTiltPos(bool state){
  Robot::m_subPCM.ptr_TiltSolenoid->Set(state);
}

bool SubCargoGrab::GetTiltPos() const {
  return m_bTiltPos;
}