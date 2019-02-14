/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "subsystems/SubHatchGrab.h"

#include "RobotMap.h"
#include "Robot.h"

SubHatchGrab::SubHatchGrab() : frc::Subsystem("SubHatchGrab") {}

void SubHatchGrab::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void SubHatchGrab::Set(bool state){
	Robot::m_subPCM.ptr_HatchSolenoid->Set(state);
}

bool SubHatchGrab::GetPos() const{
	return m_bEngageState;
}