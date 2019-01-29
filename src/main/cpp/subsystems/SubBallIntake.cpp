#include "subsystems/SubBallIntake.h"

SubBallIntake::SubBallIntake() : frc::Subsystem("SubBallIntake"){}

void SubBallIntake::Configure(){

}

void SubBallIntake::Prepare(){
	// Here will be all the code to prepare the arm 
	// for the intake system for cargo
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

