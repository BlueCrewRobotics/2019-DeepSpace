/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include "RobotMap.h"
#include "subsystems/SubPCM.h"

class SubHatchGrab : public frc::Subsystem {
	public:
		SubHatchGrab();
		void InitDefaultCommand() override;
        void Set(bool state);
        bool GetPos() const;
		void Extend4(bool state);
		void Extend7(bool state);
	private:
		// It's desirable that everything possible under private except
		// for methods that implement subsystem capabilities

		frc::Solenoid* hatchReleaseSolenoid = new frc::Solenoid(PCM_TOP, TOP_HATCH_GRABBER);
		frc::Solenoid* hatchExtend4 = new frc::Solenoid(PCM_TOP,TOP_HATCH_EXT_4);
		frc::Solenoid* hatchExtend7 = new frc::Solenoid(PCM_TOP,TOP_HATCH_EXT_7);
		
		bool m_bEngageState = 0;

};
