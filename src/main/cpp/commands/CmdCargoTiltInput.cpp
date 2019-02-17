/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdCargoTiltInput.h"

#include "Robot.h"

CmdCargoTiltInput::CmdCargoTiltInput(bool position) {
	// Use Requires() here to declare subsystem dependencies
  this->m_bPosition = position;
	Requires(&Robot::m_subCargoGrab);
}

// Called just before this Command runs the first time
void CmdCargoTiltInput::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdCargoTiltInput::Execute() {
    if( m_bPosition == 0){
    Robot::m_subCargoGrab.SetTiltPos(false);
  } else if( m_bPosition == 1){
    Robot::m_subCargoGrab.SetTiltPos(true);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool CmdCargoTiltInput::IsFinished() {
   // return true || IsTimedOut(); 
   return true;
   }

// Called once after isFinished returns true
void CmdCargoTiltInput::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdCargoTiltInput::Interrupted() {}
