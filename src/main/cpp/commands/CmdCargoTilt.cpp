/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdCargoTilt.h"

#include "Robot.h"

CmdCargoTilt::CmdCargoTilt() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subCargoGrab);
}

// Called just before this Command runs the first time
void CmdCargoTilt::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdCargoTilt::Execute() {
    bool state;
    state = Robot::m_subCargoGrab.GetTiltPos();
    state = !state;
    Robot::m_subCargoGrab.SetTiltPos(state);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdCargoTilt::IsFinished() {
   // return true || IsTimedOut(); 
   return true;
   }

// Called once after isFinished returns true
void CmdCargoTilt::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdCargoTilt::Interrupted() {}
