/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once
#include "commands/CmdCargoExtend.h"
#include "commands/CmdCargoExtendTime.h"
#include "commands/CmdCargoTilt.h"
#include "commands/CmdCargoTiltTime.h"
#include <frc/commands/CommandGroup.h>

class CmdGrpCargoRetract : public frc::CommandGroup {
public:
  CmdGrpCargoRetract();
};
