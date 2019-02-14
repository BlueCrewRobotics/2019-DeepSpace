/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdElevator.h"

#include "Robot.h"

CmdElevator::CmdElevator() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subElevator);
}

// Called just before this Command runs the first time
void CmdElevator::Initialize() {
  //SetTimeout(4);  // set 4 second timeout


}

// Called repeatedly when this Command is scheduled to run
void CmdElevator::Execute() {
  int level = Robot::m_subElevator.GetLevel();
  if(Robot::m_oi.auxController->GetPOV(0) == -1 && Robot::m_oi.auxController->GetPOV(2) == -1 && Robot::m_oi.auxController->GetPOV(4) == -1 && Robot::m_oi.auxController->GetPOV(6) == -1 ){
      Robot::m_subElevator.m_iSelection = 1;

  }

// If right is pressed
  if( Robot::m_oi.auxController->GetPOV(2) == 90 && Robot::m_subElevator.m_iSelection == 1){
      // Call elevator up top command
      // Fix the if(true) by replaceing the true with the cargo activated or hatch activated
      if(true){
        Robot::m_subElevator.ServoToPosition(Robot::m_subElevator.a_iLevelPositions[ELEVATOR_LEVEL_TOP_POS_BALL]);
        Robot::m_subElevator.SetLevel(ELEVATOR_TOP_BALL);
      }
      else {
        Robot::m_subElevator.ServoToPosition(Robot::m_subElevator.a_iLevelPositions[ELEVATOR_LEVEL_TOP_POS_HATCH]);
        Robot::m_subElevator.SetLevel(ELEVATOR_TOP_HATCH);
      }
      Robot::m_subElevator.m_iSelection = 0;
  }

// If up is pressed
  if( Robot::m_oi.auxController->GetPOV(0) == 0 && Robot::m_subElevator.m_iSelection == 1){
    // Call elevator up one level command
    if (level < ELEVATOR_LEVELS) {
      Robot::m_subElevator.ServoToPosition(Robot::m_subElevator.a_iLevelPositions[(Robot::m_subElevator.GetLevel()+1)]);
      Robot::m_subElevator.SetLevel(Robot::m_subElevator.GetLevel()+1);
    } 
    Robot::m_subElevator.m_iSelection = 0;
  }

// If left is pressed
  if( Robot::m_oi.auxController->GetPOV(6) == 270 && Robot::m_subElevator.m_iSelection == 1){
      // Call elevator down bottom command
      Robot::m_subElevator.ServoToPosition(Robot::m_subElevator.a_iLevelPositions[ELEVATOR_LEVEL_POS_HOME]);
      Robot::m_subElevator.SetLevel(ELEVATOR_HOME);
      Robot::m_subElevator.m_iSelection = 0;
  }

//if down is pressed
  if( Robot::m_oi.auxController->GetPOV(4) == 180 && Robot::m_subElevator.m_iSelection == 1){
      // Call elevator down one level command

    if (level > ELEVATOR_HOME) {
      Robot::m_subElevator.ServoToPosition(Robot::m_subElevator.a_iLevelPositions[(Robot::m_subElevator.GetLevel()-1)]);
      Robot::m_subElevator.SetLevel(Robot::m_subElevator.GetLevel()-1);
    }
    Robot::m_subElevator.m_iSelection = 0;
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
