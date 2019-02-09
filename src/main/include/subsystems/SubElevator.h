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

		//
        void ResetHomePosition();  
        void MoveElevatorToPosition(double position);  // Used for testing
        void Configure();
		int GetPosition();
		void SetLevelPositionTarget(int index, int position);
		void SetLevel(int level);
		int GetForwardLimitSwitch();
		int GetReverseLimitSwitch();



	private:
		// It's desirable that everything possible under private except
		// for methods that implement subsystem capabilities

		int a_iLevelPositions[ELEVATOR_LEVELS];
		int m_iActiveLevel = 0;
		
        TalonSRX* elevatorDrive = new TalonSRX(ELEVATOR_DRIVE_CAN_ADDR);

};
