/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "subsystems/SubHatchGrab.h"

SubHatchGrab::SubHatchGrab() : frc::Subsystem("SubHatchGrab"){}

void SubHatchGrab::Configure(){

}

void SubHatchGrab::Set(bool state){
		hatchReleaseSolenoid->Set(state);
}

void SubHatchGrab::Extend4(bool state){
	hatchExtend4->Set(state);
}

void SubHatchGrab::Extend7(bool state){
	hatchExtend7->Set(state);
}




