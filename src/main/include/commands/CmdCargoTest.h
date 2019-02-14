/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once

#include <frc/commands/Command.h>

class CmdCargoTest : public frc::Command {
	public:
		CmdCargoTest();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;
};
