/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdHatchRelease.h"

#include "Robot.h"

CmdHatchRelease::CmdHatchRelease() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subHatchGrab);
}

// Called just before this Command runs the first time
void CmdHatchRelease::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdHatchRelease::Execute() {
    Robot::m_subHatchGrab.Set(true);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdHatchRelease::IsFinished() {
   // return true || IsTimedOut(); 
   return true;
   }

// Called once after isFinished returns true
void CmdHatchRelease::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdHatchRelease::Interrupted() {}
