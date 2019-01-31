/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "subsystems/SubHatchGrab.h"

SubHatchGrab::SubHatchGrab() : frc::Subsystem("SubHatchGrab"){}

void SubHatchGrab::Configure(){

}

void SubHatchGrab::Set(bool state){
		hatchEngageSolenoid->Set(state);
}

