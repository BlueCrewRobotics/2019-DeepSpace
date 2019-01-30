/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once
#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"

class SubHatchGrab: public frc::Subsystem{
	public:
		SubHatchGrab();
		void Configure();
		void Set(bool state);

	public:
		frc::DoubleSolenoid *armPTC = new frc::DoubleSolenoid(TOP_ARM_GRABBER_FORWARD, TOP_ARM_GRABBER_REVERSE);
};
