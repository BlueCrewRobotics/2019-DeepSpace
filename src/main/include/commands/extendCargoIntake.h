/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once
#include "commands/CmdCargoExtend.h"
#include "commands/CmdCargoTilt.h"
#include <frc/commands/CommandGroup.h>

class extendCargoIntake : public frc::CommandGroup {
public:
  extendCargoIntake();
};
