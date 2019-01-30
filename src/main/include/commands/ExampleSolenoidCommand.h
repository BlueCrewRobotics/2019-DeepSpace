/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once

#include "Robot.h"

#include <frc/commands/Command.h>
#include "OI.h"
#include "subsystems/SubPCM.h"


class ExampleSolenoidCommand : public frc::Command {
	public:
		ExampleSolenoidCommand();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;
};

