/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdCargoExtendTime.h"

#include "Robot.h"

CmdCargoExtendTime::CmdCargoExtendTime(int position, double time) {
	// Use Requires() here to declare subsystem dependencies
  this->m_iPosition = position;
  this->m_dTime = time;

	Requires(&Robot::m_subCargoGrab);
}

// Called just before this Command runs the first time
void CmdCargoExtendTime::Initialize() {
    SetTimeout(m_dTime);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdCargoExtendTime::Execute() {
    if( m_iPosition == 0){
    // Neutral Cargo Position
    Robot::m_subCargoGrab.SetExtend5(false);
    Robot::m_subCargoGrab.SetExtend7(false);
  } else if( m_iPosition == 1){
    // 7 Inch piston extended only
    Robot::m_subCargoGrab.SetExtend5(false);
    Robot::m_subCargoGrab.SetExtend7(true);
  } else if( m_iPosition == 2){
    // 5 Inch piston extended only
    Robot::m_subCargoGrab.SetExtend5(true);
    Robot::m_subCargoGrab.SetExtend7(false);
  } else if( m_iPosition == 3){
    // Both Pistons extended for ball intake
    Robot::m_subCargoGrab.SetExtend5(true);
    Robot::m_subCargoGrab.SetExtend7(true);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool CmdCargoExtendTime::IsFinished() {
   // return true || IsTimedOut(); 
   return IsTimedOut(); 
}

// Called once after isFinished returns true
void CmdCargoExtendTime::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdCargoExtendTime::Interrupted() {}
