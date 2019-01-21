/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "subsystems/SubDriveTrain.h"
#include "commands/DriveWithController.h"

#include "RobotMap.h"
#include "iostream"

SubDriveTrain::SubDriveTrain() : frc::Subsystem("SubDriveTrain") {}


void SubDriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new DriveWithController());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

/*
  Configure the Talons and Victors for the drive
*/
void SubDriveTrain::Configure() {
  
  // Setup followers
	leftFollowMotor->ptr_VictorSPX->Follow(*leftDriveMotor->ptr_talonSRX);
  rightFollowMotor->ptr_VictorSPX->Follow(*rightDriveMotor->ptr_talonSRX);


  // Setup encoder
  leftDriveMotor->ptr_talonSRX->ConfigSelectedFeedbackSensor(QuadEncoder);
  leftDriveMotor->ptr_talonSRX->SetSensorPhase(false);
  rightDriveMotor->ptr_talonSRX->ConfigSelectedFeedbackSensor(QuadEncoder);
  rightDriveMotor->ptr_talonSRX->SetSensorPhase(false);
  
  // Set current limit continuous, peak, and peak duration can only be set on TalonSRX
  leftDriveMotor->ptr_talonSRX->ConfigContinuousCurrentLimit(CONTINUOUS_CURRENT_LIMIT,0.5);
  leftDriveMotor->ptr_talonSRX->ConfigPeakCurrentLimit(PEAK_CURRENT_LIMIT,0);
  leftDriveMotor->ptr_talonSRX->ConfigPeakCurrentDuration(DURATION_CURRENT_LIMIT,0);

  rightDriveMotor->ptr_talonSRX->ConfigContinuousCurrentLimit(CONTINUOUS_CURRENT_LIMIT,0.5);
  rightDriveMotor->ptr_talonSRX->ConfigPeakCurrentLimit(PEAK_CURRENT_LIMIT,0);
  rightDriveMotor->ptr_talonSRX->ConfigPeakCurrentDuration(DURATION_CURRENT_LIMIT,0);
  
  // Need to setup velocity PID controls
  leftDriveMotor->ptr_talonSRX->SelectProfileSlot(0,0);
  leftDriveMotor->ptr_talonSRX->ConfigNominalOutputForward(0,30);
  leftDriveMotor->ptr_talonSRX->ConfigNominalOutputReverse(0,30);
  leftDriveMotor->ptr_talonSRX->ConfigPeakOutputForward(12,30);
  leftDriveMotor->ptr_talonSRX->ConfigPeakOutputReverse(-12,30);

  rightDriveMotor->ptr_talonSRX->SelectProfileSlot(0,0);
  rightDriveMotor->ptr_talonSRX->ConfigNominalOutputForward(0,30);
  rightDriveMotor->ptr_talonSRX->ConfigNominalOutputReverse(0,30);
  rightDriveMotor->ptr_talonSRX->ConfigPeakOutputForward(12,30);
  rightDriveMotor->ptr_talonSRX->ConfigPeakOutputReverse(-12,30);

  // PID constants for Profile 0 of Talon
  leftDriveMotor->ptr_talonSRX->Config_kF(0,0.1097,30);
  leftDriveMotor->ptr_talonSRX->Config_kP(0,0.22,30);
  leftDriveMotor->ptr_talonSRX->Config_kI(0,0.0,30);
  leftDriveMotor->ptr_talonSRX->Config_kD(0,0.0,30);

  rightDriveMotor->ptr_talonSRX->Config_kF(0,0.1097,30);
  rightDriveMotor->ptr_talonSRX->Config_kP(0,0.22,30);
  rightDriveMotor->ptr_talonSRX->Config_kI(0,0.0,30);
  rightDriveMotor->ptr_talonSRX->Config_kD(0,0.0,30);


  // Set the Talon ramp rate in seconds from neutral to full
  leftDriveMotor->ptr_talonSRX->ConfigClosedloopRamp(RAMP_TIME,30);
  rightDriveMotor->ptr_talonSRX->ConfigClosedloopRamp(RAMP_TIME,30);
}

// Drive
void SubDriveTrain::Drive(double speed, double rotation) {
  // Drive 
  driveTrain->SetDeadband(0.05);
  driveTrain->ArcadeDrive(speed,rotation, false);
  
}


