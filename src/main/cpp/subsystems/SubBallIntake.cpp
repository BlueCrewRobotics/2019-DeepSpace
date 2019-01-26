#include "subsystems/SubBallIntake.h"

SubBallIntake::SubBallIntake() : frc::Subsystem("SubBallIntake"){}

void SubBallIntake::Configure(){

}

void SubBallIntake::Intake(){
	intakeSolenoid->Set(true);		
	leftIntake->Set(0.5);
	rightIntake->Set(-0.5);
	
}

void SubBallIntake::Deploy(){
	leftIntake->Set(-0.5);
	rightIntake->Set(0.5);
	intakeSolenoid->Set(false);
}

