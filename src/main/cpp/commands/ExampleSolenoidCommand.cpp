/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "commands/ExampleSolenoidCommand.h"

#include "Robot.h"

ExampleSolenoidCommand::ExampleSolenoidCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subsystem);
}

// Called just before this Command runs the first time
void ExampleSolenoidCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ExampleSolenoidCommand::Execute() {}

// exampleSolenoid.Set(true);
// exampleSolenoid.Set(false);

// Make this return true when this Command no longer needs to run execute()
bool ExampleSolenoidCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void ExampleSolenoidCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExampleSolenoidCommand::Interrupted() {}
