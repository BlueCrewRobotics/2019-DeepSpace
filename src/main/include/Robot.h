/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once

#include "cameraserver/CameraServer.h"
#include "frc/WPILib.h"
#include <ctre/Phoenix.h>
#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "OI.h"
#include "commands/CmdCargoClampClose.h"
#include "commands/CmdCargoClampOpen.h"
#include "commands/CmdCargoTilt.h"
#include "commands/CmdSwitchGear.h"
#include "commands/ExampleCommand.h"
#include "commands/MyAutoCommand.h"

#include "subsystems/ExampleSubsystem.h"
#include "subsystems/SubCargoGrab.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubElevator.h"
#include "subsystems/SubHatchGrab.h"
#include "subsystems/SubPCM.h"
#include "common/BC_Blinkin.h"




class Robot : public frc::TimedRobot {
	public:
		static ExampleSubsystem m_subsystem;
		static OI m_oi;
		static SubDriveTrain m_subDriveTrain;
		static SubPCM m_subPCM;
		static SubElevator m_subElevator;
		static SubCargoGrab m_subCargoGrab;
		static SubHatchGrab m_subHatchGrab;
		BC_Blinkin* m_blinkin_right = new BC_Blinkin(1);
		BC_Blinkin* m_blinkin_left = new BC_Blinkin(0);
		
		
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
