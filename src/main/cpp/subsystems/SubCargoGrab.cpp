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
  //SetDefaultCommand(new CmdCargoIntake());
  //SetDefaultCommand(new CmdCargoShoot());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
//

void SubCargoGrab::Intake(double leftspeed, double rightspeed){
  // This might need to be changed on the final robot
  leftspeed = leftspeed * -1;
	leftIntakeMotor->Set(ControlMode::PercentOutput, leftspeed);
  rightIntakeMotor->Set(ControlMode::PercentOutput, rightspeed);
}

void SubCargoGrab::Shoot(double leftspeed, double rightspeed){
  // This might need to be changed on the final robot
  rightspeed = rightspeed * -1;
	leftIntakeMotor->Set(ControlMode::PercentOutput, leftspeed);
  rightIntakeMotor->Set(ControlMode::PercentOutput, rightspeed);
}

void SubCargoGrab::Stop(){
  leftIntakeMotor->Set(ControlMode::PercentOutput, 0);
  rightIntakeMotor->Set(ControlMode::PercentOutput, 0);
}

void SubCargoGrab::ClampSet(bool state){
  Robot::m_subPCM.ptr_ClampSolenoid->Set(state);
}

void SubCargoGrab::SetTiltPos(bool state){
  Robot::m_subPCM.ptr_TiltSolenoid->Set(state);
  m_bTiltPos = state;
}

bool SubCargoGrab::GetTiltPos(){
  return m_bTiltPos;
}

// Extend the 5 inch piston
void SubCargoGrab::SetExtend5(bool state){
  cargoExtend5->Set(state);
  m_bExtend5Pos = state;
}

// Get the 5 inch piston location
bool SubCargoGrab::GetExtend5(){
  return m_bExtend5Pos;
}

// Extend the 7 inch pistion
void SubCargoGrab::SetExtend7(bool state){
  cargoExtend7->Set(state);
  m_bExtend7Pos = state;
}

// Get the 7 inch pistion location
bool SubCargoGrab::GetExtend7(){
  return m_bExtend7Pos;
}