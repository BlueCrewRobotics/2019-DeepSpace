/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdElevatorTestDown.h"

#include "Robot.h"

CmdElevatorTestDown::CmdElevatorTestDown() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subElevator);
}

// Called just before this Command runs the first time
void CmdElevatorTestDown::Initialize() {
  //SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdElevatorTestDown::Execute() {
    Robot::m_subElevator.DriveElevator(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdElevatorTestDown::IsFinished() {  
    return false; // || IsTimedOut(); 
}

// Called once after isFinished returns true
void CmdElevatorTestDown::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdElevatorTestDown::Interrupted() {}