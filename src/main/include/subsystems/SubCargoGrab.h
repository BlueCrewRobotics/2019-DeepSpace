/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include "RobotMap.h"
#include "BC_VictorSPX.h"

class SubCargoGrab : public frc::Subsystem {
	public:
		SubCargoGrab();
		void InitDefaultCommand() override;
		void Intake(double speed);
		void deploy(double speed);

	private:
		// It's desirable that everything possible under private except
		// for methods that implement subsystem capabilities
		
		frc::Solenoid* intakePositionSolenoid = 
			new frc::Solenoid(PCM_TOP, TOP_BALL_INTAKE_SOLENOID);

		frc::Solenoid* titlePositionSolenoid = new frc::Solenoid(PCM_TOP, TOP_CARGO_TILT);



		BC_VictorSPX* leftIntakeMotor = new BC_VictorSPX(BALL_INTAKE_LEFT);
		BC_VictorSPX* rightIntakeMotor = new BC_VictorSPX(BALL_INTAKE_RIGHT);
};
