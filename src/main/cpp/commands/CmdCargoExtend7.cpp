/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdCargoExtend7.h"

#include "Robot.h"

CmdCargoExtend7::CmdCargoExtend7() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subCargoGrab);
}

// Called just before this Command runs the first time
void CmdCargoExtend7::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdCargoExtend7::Execute() {
    bool state;
    state = Robot::m_subCargoGrab.GetExtend7();
    state = !state;
    Robot::m_subCargoGrab.SetExtend7(state);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdCargoExtend7::IsFinished() {
   // return true || IsTimedOut(); 
   return true;
   }

// Called once after isFinished returns true
void CmdCargoExtend7::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdCargoExtend7::Interrupted() {}
