/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdHatchGrab.h"

#include "Robot.h"

CmdHatchGrab::CmdHatchGrab() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subHatchGrab);
}

// Called just before this Command runs the first time
void CmdHatchGrab::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdHatchGrab::Execute() {
    Robot::m_subHatchGrab.Set(false);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdHatchGrab::IsFinished() {
   // return true || IsTimedOut(); 
   return true;
   }

// Called once after isFinished returns true
void CmdHatchGrab::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdHatchGrab::Interrupted() {}
