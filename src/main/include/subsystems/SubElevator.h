/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once

#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class SubElevator : public frc::Subsystem {
	public:
		SubElevator();
		void InitDefaultCommand() override;

		//
        void ResetHomePosition();  
        void MoveElevatorToPosition(int position);  // Used for testing
        void Configure();
		int GetPosition();
		//void SetLevelPositionTarget(int index, int position);
		void SetBallPositionTarget(int index, int position);
		void SetHatchPositionTarget(int idex, int position);
		//void SetLevel(int level);
		void SetBallLevel(int level);
		void SetHatchLevel(int level);
		int GetUpLimitSwitch();
		int GetDownLimitSwitch();
		void DriveElevator(double output);
		void ServoToPosition(double position);
		//int GetLevel();
		int GetBallLevel();
		int GetHatchLevel();
		int GetPIDerror();
		double GetPIDtarget();

		//int a_iLevelPositions[ELEVATOR_LEVELS];

		int a_iBallLevelPos[ELEVATOR_BALL_LEVELS];		// Ball deploy locations
		int a_iHatchLevelPos[ELEVATOR_HATCH_LEVELS];	// Hatch deploy locations

		int m_iSelection = 0;
		
	private:
		// It's desirable that everything possible under private except
		// for methods that implement subsystem capabilities


		int m_iActiveLevel = 0;			// Update when at a level
		int m_iBallLevel = 0;			// Update when at a ball level
		int m_iHatchLevel = 0;			// Update when at a hatch level		
		bool m_bMovingUp = false;		// Update when moving up
		bool m_bMovingdown = false;		// Update when moving down
		bool m_bStationary = false;		// Update when at a level

		
        TalonSRX* elevatorDrive = new TalonSRX(ELEVATOR_DRIVE_CAN_ADDR);

};
