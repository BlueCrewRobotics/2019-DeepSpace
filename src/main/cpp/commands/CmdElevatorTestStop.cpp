/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "commands/CmdElevatorTestStop.h"

#include "Robot.h"

CmdElevatorTestStop::CmdElevatorTestStop() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subElevator);
}

// Called just before this Command runs the first time
void CmdElevatorTestStop::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdElevatorTestStop::Execute() { Robot::m_subElevator.DriveElevator(0); }

// Make this return true when this Command no longer needs to run execute()
bool CmdElevatorTestStop::IsFinished() {
  return true; //|| IsTimedOut();
}

// Called once after isFinished returns true
void CmdElevatorTestStop::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdElevatorTestStop::Interrupted() {}
