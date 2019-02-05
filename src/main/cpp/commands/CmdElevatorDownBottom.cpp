/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdElevatorDownBottom.h"

#include "Robot.h"

CmdElevatorDownBottom::CmdElevatorDownBottom() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subElevator);
}

// Called just before this Command runs the first time
void CmdElevatorDownBottom::Initialize() {
  SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdElevatorDownBottom::Execute() {
    
}

// Make this return true when this Command no longer needs to run execute()
bool CmdElevatorDownBottom::IsFinished() {
   return true || IsTimedOut(); 
   }

// Called once after isFinished returns true
void CmdElevatorDownBottom::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdElevatorDownBottom::Interrupted() {}
