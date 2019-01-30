/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/ExampleCommand.h"

#include "Robot.h"

ExampleCommand::ExampleCommand() {
	// Use Requires() here to declare subsystem dependencies
	Requires(&Robot::m_subsystem);
}

// Called just before this Command runs the first time
void ExampleCommand::Initialize() {
  SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void ExampleCommand::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool ExampleCommand::IsFinished() {
   return true || IsTimedOut(); 
   }

// Called once after isFinished returns true
void ExampleCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExampleCommand::Interrupted() {}
