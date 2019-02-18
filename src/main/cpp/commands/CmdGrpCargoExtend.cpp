/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdGrpCargoExtend.h"

CmdGrpCargoExtend::CmdGrpCargoExtend(){
	CommandGroup::AddSequential(new CmdCargoTilt(true));
	CommandGroup::AddParallel(new CmdCargoExtend(3)); // Needs to change (0)
	CommandGroup::AddSequential(new CmdCargoTilt(false));
}



