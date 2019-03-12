/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once
#include <frc/commands/CommandGroup.h>
#include "commands/CmdGrpCargoRetract.h"
#include "CmdHatchExt.h"

class CmdGrpHatchCargoNeutral: public frc::CommandGroup {
	public:
		CmdGrpHatchCargoNeutral();
};