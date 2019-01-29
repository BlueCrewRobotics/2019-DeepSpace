/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once

#include "Robot.h"

#include "OI.h"
#include "subsystems/SubDriveTrain.h"

#include <frc/commands/Command.h>

class DriveWithController : public frc::Command {
	public:
		DriveWithController();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;
};
