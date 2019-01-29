/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class SubElevator : public frc::Subsystem {
	public:
		SubElevator();
		void InitDefaultCommand() override;

		// Set limit switches top and bottom
		// Configure TalonSRX for position control
		//

		TalonSRX* elevatorDrive = new TalonSRX(ELEVATOR_DRIVE_CAN_ADDR);

	private:
		// It's desirable that everything possible under private except
		// for methods that implement subsystem capabilities

};
