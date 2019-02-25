/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "commands/CmdHatchExt.h"

#include "Robot.h"

CmdHatchExt::CmdHatchExt(int position) {
  // Use Requires() here to declare subsystem dependencies
  this->m_iPosition = position;
  Requires(&Robot::m_subHatchGrab);
}

// Called just before this Command runs the first time
void CmdHatchExt::Initialize() {
  // SetTimeout(4);  // set 4 second timeout
}

// Called repeatedly when this Command is scheduled to run
void CmdHatchExt::Execute() {
  if (m_iPosition == 0) {
    // Neutral Hatch Position
    Robot::m_subHatchGrab.Extend4(false);
    Robot::m_subHatchGrab.Extend7(false);
  } else if (m_iPosition == 1) {
    // 7 Inch piston extended only
    Robot::m_subHatchGrab.Extend4(false);
    Robot::m_subHatchGrab.Extend7(true);
  } else if (m_iPosition == 2) {
    // Both pistions extended for placing hatch panels
    Robot::m_subHatchGrab.Extend4(true);
    Robot::m_subHatchGrab.Extend7(true);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool CmdHatchExt::IsFinished() {
  return true;
  // return true || IsTimedOut();
}

// Called once after isFinished returns true
void CmdHatchExt::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdHatchExt::Interrupted() {}
