/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once
#include <frc/commands/CommandGroup.h>
#include "commands/CmdCargoTilt.h"
#include "commands/CmdCargoExtend5.h"
#include "commands/CmdCargoExtend7.h"

class extendCargoIntake: public frc::CommandGroup {
	public:
		extendCargoIntake();
};
