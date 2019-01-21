#include "subsystems/SubHatchGrab.h"

SubHatchGrab::SubHatchGrab() : frc::Subsystem("SubHatchGrab"){}

void SubHatchGrab::Configure(){

}

void SubHatchGrab::Grab(){
				armPTC->Set(frc::DoubleSolenoid::Value::kForward);
}

void SubHatchGrab::Deploy(){
				armPTC->Set(frc::DoubleSolenoid::Value::kReverse);
}
