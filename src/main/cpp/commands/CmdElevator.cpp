/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "commands/CmdElevator.h"

#include "Robot.h"
#include <iostream>

CmdElevator::CmdElevator() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subElevator);
}

// Called just before this Command runs the first time
void CmdElevator::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdElevator::Execute() {
  int ballLevel = Robot::m_subElevator.GetBallLevel();
  int hatchLevel = Robot::m_subElevator.GetHatchLevel();

  bool hatchBallSelection = Robot::m_oi.m_bHatchCargoCurrent; 
  // This needs to be changed based on
  // hatch or cargo selection

  if (Robot::m_oi.auxController->GetPOV(0) == -1) {
    Robot::m_subElevator.m_iSelection = 1;
  }
  
  // If up is pressed
  if (Robot::m_oi.auxController->GetPOV(0) == 0 &&
      Robot::m_subElevator.m_iSelection == 1) {
    // Call elevator up one level command
    if (hatchBallSelection == false) { 
      // Ball deploy selected
      if (ballLevel < ELEVATOR_BALL_LEVELS - 1) {
        Robot::m_subElevator.ServoToPosition(Robot::m_subElevator.a_iBallLevelPos[(ballLevel + 1)]);
        Robot::m_subElevator.SetBallLevel(ballLevel + 1);
        Robot::m_subElevator.m_iSelection = 0;
        // std::cout << Robot::m_subElevator.GetBallLevel() << std::endl;
        // Automation tilt the cargo holder for shooting
        if (Robot::m_subElevator.GetBallLevel() > (ELEV_BALL_GRAB)) {
          Robot::m_oi.elevCargoTilt->SetPressed(false);
          // std::cout << "Elev Tilt up " << Robot::m_oi.elevCargoTilt->Get() <<
          // std::endl;
        } else {
          Robot::m_oi.elevCargoTilt->SetPressed(true);
          // std::cout << "Elev Tilt down " << Robot::m_oi.elevCargoTilt->Get()
          // << std::endl;
        }
        // Set the ramp level when higher than first level
        if (Robot::m_subElevator.GetBallLevel() > 2) {
          Robot::m_subDriveTrain.SetRamp(ELEV_DRIVE_RAMP_TOP);
        } else {
          Robot::m_subDriveTrain.SetRamp(ELEV_DRIVE_RAMP_BTM);
        }
      }
      switch(Robot::m_subElevator.GetBallLevel()){
        case 0: Robot::m_subCargoGrab.m_dShootingSpeed = 0.8;
        case 1: Robot::m_subCargoGrab.m_dShootingSpeed = 0.5;
        case 2: Robot::m_subCargoGrab.m_dShootingSpeed = 0.25;
        case 3: Robot::m_subCargoGrab.m_dShootingSpeed = 0.5;
        case 4: Robot::m_subCargoGrab.m_dShootingSpeed = 0.8;

      }
    }
    if (hatchBallSelection == true) { // Hatch deploy selected
      if (hatchLevel < ELEVATOR_HATCH_LEVELS - 1) {
        Robot::m_subElevator.ServoToPosition(
            Robot::m_subElevator.a_iHatchLevelPos[(hatchLevel + 1)]);
        Robot::m_subElevator.SetHatchLevel(hatchLevel + 1);
        Robot::m_subElevator.m_iSelection = 0;
        // Set the ramp level when higher than first level
        if (hatchLevel > 1) {
          Robot::m_subDriveTrain.SetRamp(ELEV_DRIVE_RAMP_TOP);
        } else {
          Robot::m_subDriveTrain.SetRamp(ELEV_DRIVE_RAMP_BTM);
        }
      }
    }
  }

  // if down is pressed
  if (Robot::m_oi.auxController->GetPOV(0) == 180 &&
      Robot::m_subElevator.m_iSelection == 1) {
    // Call elevator down one level command
    if (hatchBallSelection == false) { // Ball deploy selected
      if (ballLevel > (ELEV_BALL_GRAB)) {
        Robot::m_subElevator.ServoToPosition(
            Robot::m_subElevator.a_iBallLevelPos[(ballLevel - 1)]);
        Robot::m_subElevator.SetBallLevel(ballLevel - 1);
        Robot::m_subElevator.m_iSelection = 0;
      }
      if (Robot::m_subElevator.GetBallLevel() > (ELEV_BALL_GRAB)) {
        Robot::m_oi.elevCargoTilt->SetPressed(false);
      } else {
        Robot::m_oi.elevCargoTilt->SetPressed(true);
      }
      // Set the ramp level when higher than first level
      if (Robot::m_subElevator.GetBallLevel() > 2) {
        Robot::m_subDriveTrain.SetRamp(ELEV_DRIVE_RAMP_TOP);
      } else {
        Robot::m_subDriveTrain.SetRamp(ELEV_DRIVE_RAMP_BTM);
      }
     switch(Robot::m_subElevator.GetBallLevel()){
        case 0: Robot::m_subCargoGrab.m_dShootingSpeed = 0.8;
        case 1: Robot::m_subCargoGrab.m_dShootingSpeed = 0.5;
        case 2: Robot::m_subCargoGrab.m_dShootingSpeed = 0.25;
        case 3: Robot::m_subCargoGrab.m_dShootingSpeed = 0.5;
        case 4: Robot::m_subCargoGrab.m_dShootingSpeed = 0.8;
     }
    }
    if (hatchBallSelection == true) { // Hatch deploy selected
      if (hatchLevel > (ELEV_HATCH_ROCKET_BTM - 1)) {
        Robot::m_subElevator.ServoToPosition(
            Robot::m_subElevator.a_iHatchLevelPos[(hatchLevel - 1)]);
        Robot::m_subElevator.SetHatchLevel(hatchLevel - 1);
        Robot::m_subElevator.m_iSelection = 0;
      }
      // Set the ramp level when higher than first level
      if (hatchLevel > 1) {
        Robot::m_subDriveTrain.SetRamp(ELEV_DRIVE_RAMP_TOP);
      } else {
        Robot::m_subDriveTrain.SetRamp(ELEV_DRIVE_RAMP_BTM);
      }
    }
  }
}

// Make this return true when this Command no longer needs to run execute()
bool CmdElevator::IsFinished() {
  return false; //|| IsTimedOut();
}

// Called once after isFinished returns true
void CmdElevator::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdElevator::Interrupted() {}
