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
	leftFollowMotor->Follow(*leftDriveMotor);
  rightFollowMotor->Follow(*rightDriveMotor);


  // Setup encoder
  leftDriveMotor->ConfigSelectedFeedbackSensor(QuadEncoder);
  leftDriveMotor->SetSensorPhase(false);
  rightDriveMotor->ConfigSelectedFeedbackSensor(QuadEncoder);
  rightDriveMotor->SetSensorPhase(false);
  
  // Set current limit continuous, peak, and peak duration can only be set on TalonSRX
  leftDriveMotor->ConfigContinuousCurrentLimit(CONTINUOUS_CURRENT_LIMIT,0.5);
  leftDriveMotor->ConfigPeakCurrentLimit(PEAK_CURRENT_LIMIT,0);
  leftDriveMotor->ConfigPeakCurrentDuration(DURATION_CURRENT_LIMIT,0);

  rightDriveMotor->ConfigContinuousCurrentLimit(CONTINUOUS_CURRENT_LIMIT,0.5);
  rightDriveMotor->ConfigPeakCurrentLimit(PEAK_CURRENT_LIMIT,0);
  rightDriveMotor->ConfigPeakCurrentDuration(DURATION_CURRENT_LIMIT,0);
  
  // Need to setup velocity PID controls
  leftDriveMotor->SelectProfileSlot(0,0);
  leftDriveMotor->ConfigNominalOutputForward(0,30);
  leftDriveMotor->ConfigNominalOutputReverse(0,30);
  leftDriveMotor->ConfigPeakOutputForward(12,30);
  leftDriveMotor->ConfigPeakOutputReverse(-12,30);

  rightDriveMotor->SelectProfileSlot(0,0);
  rightDriveMotor->ConfigNominalOutputForward(0,30);
  rightDriveMotor->ConfigNominalOutputReverse(0,30);
  rightDriveMotor->ConfigPeakOutputForward(12,30);
  rightDriveMotor->ConfigPeakOutputReverse(-12,30);

  // PID constants for Profile 0 of Talon
  leftDriveMotor->Config_kF(0,0.1097,30);
  leftDriveMotor->Config_kP(0,0.22,30);
  leftDriveMotor->Config_kI(0,0.0,30);
  leftDriveMotor->Config_kD(0,0.0,30);

  rightDriveMotor->Config_kF(0,0.1097,30);
  rightDriveMotor->Config_kP(0,0.22,30);
  rightDriveMotor->Config_kI(0,0.0,30);
  rightDriveMotor->Config_kD(0,0.0,30);


  // Set the Talon ramp rate in seconds from neutral to full
  leftDriveMotor->ConfigClosedloopRamp(0.5,0);
  rightDriveMotor->ConfigClosedloopRamp(0.5,0);


}

// Drive
void SubDriveTrain::Drive(double speed, double rotation) {
  // Drive 
  
  driveTrain->ArcadeDrive(speed,rotation, false);
}

//Drive with velocity control
void SubDriveTrain::DriveVelocityControl(double speed, double rotation) {
  
  double leftDriveSetpoint;
  double rightDriveSetpoint;  
  // Check if we need to turn will driving
  
    double maxInput =
      std::copysign(std::max(std::abs(speed), std::abs(rotation)), speed);

  if (speed >= 0.0) {
    // First quadrant, else second quadrant
    if (rotation >= 0.0) {
      leftDriveSetpoint = maxInput;
      rightDriveSetpoint = speed - rotation;
    } else {
      leftDriveSetpoint = speed + rotation;
      rightDriveSetpoint = maxInput;
    }
  } else {
    // Third quadrant, else fourth quadrant
    if (rotation >= 0.0) {
      leftDriveSetpoint = speed + rotation;
      rightDriveSetpoint = maxInput;
    } else {
      leftDriveSetpoint = maxInput;
      rightDriveSetpoint = speed - rotation;
    }
  }

   /*
  if (speed > 0.0) {
    // If turn to the right
    if (rotation > 0.0) {
      leftDriveSetpoint = (speed)*VELOCITY_MAX;
      rightDriveSetpoint = -1*(speed - rotation)*VELOCITY_MAX;
    } 
    // Else turn to the left
    else {
      leftDriveSetpoint = (speed + rotation)*VELOCITY_MAX;
      rightDriveSetpoint = -1*(speed)*VELOCITY_MAX;
    }
  } 
  else 
  {
    // Turn right without driving
    if (rotation > 0.0 || rotation < 0.0){
      leftDriveSetpoint = (rotation)*VELOCITY_MAX;
      rightDriveSetpoint = -1*(rotation)*VELOCITY_MAX;
    } 
    // Turn left without driving
    /*
    else if (rotation < 0.0){
      leftDriveSetpoint = (rotation)*VELOCITY_MAX;
      rightDriveSetpoint = -1*leftDriveSetpoint;
    }
    */
  //}
  
  // Set the Talons to velocity control mode

  leftDriveMotor->Set(ctre::phoenix::motorcontrol::ControlMode::Velocity, leftDriveSetpoint);
  rightDriveMotor->Set(ctre::phoenix::motorcontrol::ControlMode::Velocity, -1*rightDriveSetpoint);  

  
  
    /* append more signals to print when in speed mode. */
    std::cout << "\L_err:";
    std::cout << leftDriveMotor->GetClosedLoopError(0);
    std::cout << "\L_setpoint:";
    std::cout << leftDriveSetpoint;

    std::cout << "\R_err:";
    std::cout << rightDriveMotor->GetClosedLoopError(0);
    std::cout << "\R_setpoint:";
    std::cout << rightDriveSetpoint;


}



