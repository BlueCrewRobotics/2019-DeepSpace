/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <ctre/Phoenix.h>

#include "OI.h"
#include "commands/ExampleCommand.h"
#include "commands/MyAutoCommand.h"
#include "commands/CmdSwitchGear.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubPCM.h"


class Robot : public frc::TimedRobot {
	public:
		static ExampleSubsystem m_subsystem;
		static OI m_oi;
		static SubDriveTrain m_subDriveTrain;
		static SubPCM m_subPCM;

		void RobotInit() override;
		void RobotPeriodic() override;
		void DisabledInit() override;
		void DisabledPeriodic() override;
		void AutonomousInit() override;
		void AutonomousPeriodic() override;
		void TeleopInit() override;
		void TeleopPeriodic() override;
		void TestPeriodic() override;

	private:
		// Have it null by default so that if testing teleop it
		// doesn't have undefined behavior and potentially crash.
		frc::Command* m_autonomousCommand = nullptr;
		ExampleCommand m_defaultAuto;
		MyAutoCommand m_myAuto;
		frc::SendableChooser<frc::Command*> m_chooser;
};
