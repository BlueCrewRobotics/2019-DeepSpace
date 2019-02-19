/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once
#include <frc/commands/CommandGroup.h>
#include "commands/CmdCargoTiltTime.h"
#include "commands/CmdCargoTilt.h"
#include "commands/CmdCargoExtend.h"
#include "commands/CmdCargoExtendTime.h"

class CmdGrpCargoExtend: public frc::CommandGroup {
	public:
		CmdGrpCargoExtend();
};
