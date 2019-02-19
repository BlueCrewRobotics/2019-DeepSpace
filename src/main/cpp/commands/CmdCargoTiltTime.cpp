/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdCargoTiltTime.h"

#include "Robot.h"

CmdCargoTiltTime::CmdCargoTiltTime(bool state, double time) {
  this->m_bState = state;
  this->m_dTime = time;
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subCargoGrab);
}

// Called just before this Command runs the first time
void CmdCargoTiltTime::Initialize() {
   SetTimeout(m_dTime);  // set x second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdCargoTiltTime::Execute() {
    //bool state;
    //state = Robot::m_oi.cargoTiltTrigger->Get();
    //state = Robot::m_subCargoGrab.GetTiltPos();
    //state = !state;
    Robot::m_subCargoGrab.SetTiltPos(m_bState);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdCargoTiltTime::IsFinished() {
   return IsTimedOut();  

}
// Called once after isFinished returns true
void CmdCargoTiltTime::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdCargoTiltTime::Interrupted() {}
