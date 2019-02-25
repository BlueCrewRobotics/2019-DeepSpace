/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "commands/CmdCargoClampClose.h"

#include "Robot.h"

CmdCargoClampClose::CmdCargoClampClose() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subCargoGrab);
}

// Called just before this Command runs the first time
void CmdCargoClampClose::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdCargoClampClose::Execute() {
  // Closes clamp
  Robot::m_subCargoGrab.ClampSet(false);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdCargoClampClose::IsFinished() {
  // return true || IsTimedOut();
  return true;
}

// Called once after isFinished returns true
void CmdCargoClampClose::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdCargoClampClose::Interrupted() {}
