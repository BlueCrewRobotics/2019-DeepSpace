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
		void Extend4(bool state);
		void Extend7(bool state);

	public:
		frc::Solenoid* hatchReleaseSolenoid = new frc::Solenoid(PCM_TOP, TOP_HATCH_GRABBER);

		frc::Solenoid* hatchExtend4 = new frc::Solenoid(PCM_TOP,TOP_HATCH_EXT_4);
		frc::Solenoid* hatchExtend7 = new frc::Solenoid(PCM_TOP,TOP_HATCH_EXT_7);

		//frc::DoubleSolenoid* PositionSetSolenoid = 
		//	new frc::DoubleSolenoid(PCM_TOP, TOP_HATCH_POSITION_FORWARD, TOP_HATCH_POSITION_REVERSE);
};
