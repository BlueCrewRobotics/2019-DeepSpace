/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "subsystems/SubLed.h"

#include "RobotMap.h"

SubLed::SubLed() : frc::Subsystem("SubLed") {}

void SubLed::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem

void SubLed::setLedColor(float colorCode){
	ledController->Set(colorCode);
}
