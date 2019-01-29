#include "subsystems/SubHatchGrab.h"

SubHatchGrab::SubHatchGrab() : frc::Subsystem("SubHatchGrab"){}

void SubHatchGrab::Configure(){

}
 
void SubHatchGrab::Set(bool state){
				if(state){
					armPTC->Set(frc::DoubleSolenoid::Value::kForward);
				} else {
					armPTC->Set(frc::DoubleSolenoid::Value::kReverse);
				}
}

