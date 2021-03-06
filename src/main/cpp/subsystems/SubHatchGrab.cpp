/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "subsystems/SubHatchGrab.h"

#include "Robot.h"
#include "RobotMap.h"

SubHatchGrab::SubHatchGrab() : frc::Subsystem("SubHatchGrab") {}

void SubHatchGrab::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  // SetDefaultCommand(new MySpecialCommand());
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void SubHatchGrab::Set(bool state) {

  hatchReleaseSolenoid->Set(state);
  m_bEngageState = state;
}

void SubHatchGrab::Extend4(bool state) { hatchExtend4->Set(state); }

void SubHatchGrab::Extend7(bool state) { hatchExtend7->Set(state); }

bool SubHatchGrab::GetHatchPos() { return m_bEngageState; }

bool SubHatchGrab::hatchIsOn() { return hatchDetectHallEffect->Get(); }
