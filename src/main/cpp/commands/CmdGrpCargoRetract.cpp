/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdGrpCargoRetract.h"

CmdGrpCargoRetract::CmdGrpCargoRetract(){
	CommandGroup::AddSequential(new CmdCargoTilt(true));
	CommandGroup::AddParallel(new CmdCargoExtend(0)); 
	CommandGroup::AddSequential(new CmdCargoTilt(false));
}

