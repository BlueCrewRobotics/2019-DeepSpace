/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include "frc/WPILib.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <ctre/Phoenix.h>
#include "cameraserver/CameraServer.h"

#include "OI.h"
#include "commands/ExampleCommand.h"
#include "commands/MyAutoCommand.h"
#include "commands/CmdSwitchGear.h"
#include "commands/CmdCargoClampOpen.h"
#include "commands/CmdCargoClampClose.h"
#include "commands/CmdCargoTilt.h"

#include "subsystems/ExampleSubsystem.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubPCM.h"
#include "subsystems/SubElevator.h"
#include "subsystems/SubCargoGrab.h"


class Robot : public frc::TimedRobot {
	public:
		static ExampleSubsystem m_subsystem;
		static OI m_oi;
		static SubDriveTrain m_subDriveTrain;
		static SubPCM m_subPCM;
		static SubElevator m_subElevator;
		
		static SubCargoGrab m_subCargoGrab;
    // static CameraServer m_cameraServer;

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
