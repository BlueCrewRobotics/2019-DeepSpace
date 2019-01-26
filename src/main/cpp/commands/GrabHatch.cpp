#include "commands/GrabHatch.h"

#include "Robot.h"

GrabHatch::GrabHatch(){
				Requires(&Robot::m_subsystem);
}

void GrabHatch::Initialize() {

}

void GrabHatch::Execute(){
	if(Robot::m_oi.driverController->GetRawButton(BUTTON_A)){
				state = !state;
				hatchgrabber->Set(state);
	}
}

bool GrabHatch::IsFinished(){}

void GrabHatch::End(){}

void GrabHatch::Interrupted(){}
