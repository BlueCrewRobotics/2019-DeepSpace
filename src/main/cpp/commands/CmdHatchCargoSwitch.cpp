/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "commands/CmdHatchCargoSwitch.h"
#include "Robot.h"
#include <iostream>

CmdHatchCargoSwitch::CmdHatchCargoSwitch() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subCargoGrab);
  Requires(&Robot::m_subHatchGrab);
}

// Called just before this Command runs the first time
void CmdHatchCargoSwitch::Initialize() {
  if (Robot::m_oi.m_bHatchCargoCurrent == 0) {
    m_bPosition = Robot::m_oi.m_bHatchCargoCurrent;
  } else {
    m_bPosition = 1;
  }
}

// Called repeatedly when this Command is scheduled to run
void CmdHatchCargoSwitch::Execute() {
  m_bPosition = Robot::m_oi.m_bHatchCargoCurrent;
  m_bPosition = !m_bPosition;

  if (m_bPosition == 1) {
    Robot::m_subCargoGrab.SetTiltPos(false);
    Robot::m_subHatchGrab.Extend7(true);
    Robot::m_subHatchGrab.Extend4(false);
    Robot::m_subCargoGrab.SetExtend7(false);
    Robot::m_subCargoGrab.SetExtend5(false);
    Robot::m_oi.m_bHatchCargoCurrent = m_bPosition;
  } else if (m_bPosition == 0) {
    Robot::m_subCargoGrab.SetTiltPos(false);
    Robot::m_subHatchGrab.Extend7(false);
    Robot::m_subHatchGrab.Extend4(false);
    Robot::m_subCargoGrab.SetExtend7(false);
    Robot::m_subCargoGrab.SetExtend5(false);
    Robot::m_oi.m_bHatchCargoCurrent = m_bPosition;
  }
}

// Make this return true when this Command no longer needs to run execute()
bool CmdHatchCargoSwitch::IsFinished() {
  // return true || IsTimedOut();
  return true;
}

// Called once after isFinished returns true
void CmdHatchCargoSwitch::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdHatchCargoSwitch::Interrupted() {}
