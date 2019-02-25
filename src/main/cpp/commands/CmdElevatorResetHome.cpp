/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "commands/CmdElevatorResetHome.h"

#include "Robot.h"

CmdElevatorResetHome::CmdElevatorResetHome() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subElevator);
}

// Called just before this Command runs the first time
void CmdElevatorResetHome::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdElevatorResetHome::Execute() {
  Robot::m_subElevator.ResetHomePosition();
}

// Make this return true when this Command no longer needs to run execute()
bool CmdElevatorResetHome::IsFinished() {
  return true; //|| IsTimedOut();
}

// Called once after isFinished returns true
void CmdElevatorResetHome::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdElevatorResetHome::Interrupted() {}
