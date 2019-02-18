/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdHatchCargoNeutral.h"

#include "Robot.h"

CmdHatchCargoNeutral::CmdHatchCargoNeutral() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subsystem);
}

// Called just before this Command runs the first time
void CmdHatchCargoNeutral::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdHatchCargoNeutral::Execute() {
    Robot::m_subHatchGrab.Extend7(false);
    Robot::m_subHatchGrab.Extend4(false);
    Robot::m_subCargoGrab.SetExtend7(false);
    Robot::m_subCargoGrab.SetExtend5(false);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdHatchCargoNeutral::IsFinished() {
   // return true || IsTimedOut(); 
   return true;
   }

// Called once after isFinished returns true
void CmdHatchCargoNeutral::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdHatchCargoNeutral::Interrupted() {}
