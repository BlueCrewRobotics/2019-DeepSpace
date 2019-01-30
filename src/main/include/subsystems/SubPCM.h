/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include "frc/Compressor.h"
#include "RobotMap.h"

class SubPCM : public frc::Subsystem {
	public:

		SubPCM();
		void InitDefaultCommand() override;
		void Configure();
		frc::Solenoid* ptr_GearSoleniod = new frc::Solenoid(PCM_BOTTOM, BTM_GEARSHIFT);

	private:
		// It's desirable that everything possible under private except
		// for methods that implement subsystem capabilities
		frc::Compressor* compressor = new frc::Compressor(0);
		// frc::Solenoid exampleSolenoid {1};


};
