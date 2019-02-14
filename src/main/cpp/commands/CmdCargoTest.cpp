/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdCargoTest.h"

#include "Robot.h"

CmdCargoTest::CmdCargoTest() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subsystem);
}

// Called just before this Command runs the first time
void CmdCargoTest::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdCargoTest::Execute() {
  Robot::m_subCargoGrab.Stop();
}

// Make this return true when this Command no longer needs to run execute()
bool CmdCargoTest::IsFinished() {
   // return true || IsTimedOut(); 
   
   return true;
   }

// Called once after isFinished returns true
void CmdCargoTest::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdCargoTest::Interrupted() {}
