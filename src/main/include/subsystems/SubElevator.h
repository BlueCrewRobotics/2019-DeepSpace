/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

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
