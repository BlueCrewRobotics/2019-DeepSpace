/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once
#include "RobotMap.h"
#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "subsystems/BC_TalonSRX.h"
#include "subsystems/BC_VictorSPX.h"

class SubBallIntake : public frc::Subsystem {

	public:
		SubBallIntake();
		void Configure();
		void Prepare();
		void Intake();
		void Deploy();

	public:
		BC_VictorSPX * leftIntake = new BC_VictorSPX(BALL_INTAKE_LEFT);
		BC_VictorSPX * rightIntake = new BC_VictorSPX(BALL_INTAKE_RIGHT);
		frc::Solenoid * intakeSolenoid = new frc::Solenoid(BALL_INTAKE_SOLENOID);

};
