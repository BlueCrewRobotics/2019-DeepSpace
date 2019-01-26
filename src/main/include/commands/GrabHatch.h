#pragma once 

#include "Robot.h"

#include "OI.h"
#include "subsystems/SubHatchGrab.h"

#include <frc/commands/Command.h>

class GrabHatch : public frc::Command {
	public:
		GrabHatch();
		void Initialize() override;
  	void Execute() override;
  	bool IsFinished() override;
  	void End() override;
  	void Interrupted() override;
	private:
		bool state = false;
		SubHatchGrab * hatchgrabber = new SubHatchGrab();	
};
