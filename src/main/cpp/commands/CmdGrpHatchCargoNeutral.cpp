/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdGrpHatchCargoNeutral.h"

CmdGrpHatchCargoNeutral::CmdGrpHatchCargoNeutral(){
	CommandGroup::AddParallel(new CmdGrpCargoRetract());
	CommandGroup::AddParallel(new CmdHatchExt(0)); 
	//CommandGroup::AddSequential(new CmdCargoTilt(false));
}

