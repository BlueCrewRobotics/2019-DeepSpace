/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdGrpCargoRetract.h"

CmdGrpCargoRetract::CmdGrpCargoRetract(){
	CommandGroup::AddSequential(new CmdCargoTilt(true));
	CommandGroup::AddSequential(new CmdCargoExtendTime(0,0.5)); 
	//CommandGroup::AddSequential(new CmdCargoTilt(false));
}

