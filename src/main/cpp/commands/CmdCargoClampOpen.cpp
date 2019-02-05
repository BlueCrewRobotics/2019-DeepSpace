/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdCargoClampOpen.h"

#include "Robot.h"

CmdCargoClampOpen::CmdCargoClampOpen() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subCargoGrab);
}

// Called just before this Command runs the first time
void CmdCargoClampOpen::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdCargoClampOpen::Execute() {
    // Opens clamp
    Robot::m_subCargoGrab.ClampSet(true);

}

// Make this return true when this Command no longer needs to run execute()
bool CmdCargoClampOpen::IsFinished() {
   // return true || IsTimedOut(); 
   return true;
   }

// Called once after isFinished returns true
void CmdCargoClampOpen::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdCargoClampOpen::Interrupted() {}
