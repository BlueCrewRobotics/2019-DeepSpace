/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdCargoIntake.h"

#include "Robot.h"

CmdCargoIntake::CmdCargoIntake() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subCargoGrab);
}

// Called just before this Command runs the first time
void CmdCargoIntake::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdCargoIntake::Execute() {

  Robot::m_subCargoGrab.Intake(0.5, 0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdCargoIntake::IsFinished() {
   // return true || IsTimedOut(); 
   // Robot::m_subCargoGrab.Stop();
   return true;
   }

// Called once after isFinished returns true
void CmdCargoIntake::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdCargoIntake::Interrupted() {}
