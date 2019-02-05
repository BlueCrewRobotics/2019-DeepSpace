/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

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
	leftIntakeMotor->Set(leftspeed);
  rightIntakeMotor->Set(rightspeed);
}

void SubCargoGrab::Shoot(double leftspeed, double rightspeed){
	leftIntakeMotor->Set(leftspeed);
  rightIntakeMotor->Set(rightspeed);
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