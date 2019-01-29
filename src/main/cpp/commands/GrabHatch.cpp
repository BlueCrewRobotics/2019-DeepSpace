#include "commands/GrabHatch.h"

#include "Robot.h"

GrabHatch::GrabHatch(){
	Requires(&Robot::m_subsystem);
}

void GrabHatch::Initialize() {

}

void GrabHatch::Execute(){
	state = !state;
	hatchgrabber->Set(state);
}

bool GrabHatch::IsFinished(){}

void GrabHatch::End(){}

void GrabHatch::Interrupted(){}
