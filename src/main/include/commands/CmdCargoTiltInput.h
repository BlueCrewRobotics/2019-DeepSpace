/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once

#include <frc/commands/Command.h>

class CmdCargoTiltInput : public frc::Command {
	public:
		CmdCargoTiltInput(bool position);
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;
	private:
		bool m_bPosition;
};
