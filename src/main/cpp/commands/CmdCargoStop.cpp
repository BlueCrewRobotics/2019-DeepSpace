/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdCargoStop.h"

#include "Robot.h"

CmdCargoStop::CmdCargoStop() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subCargoGrab);
}

// Called just before this Command runs the first time
void CmdCargoStop::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdCargoStop::Execute() {
  Robot::m_subCargoGrab.Stop();
}

// Make this return true when this Command no longer needs to run execute()
bool CmdCargoStop::IsFinished() {
   // return true || IsTimedOut(); 
   
   return true;
   }

// Called once after isFinished returns true
void CmdCargoStop::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdCargoStop::Interrupted() {}
