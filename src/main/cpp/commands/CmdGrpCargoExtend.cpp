/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "commands/CmdGrpCargoExtend.h"

CmdGrpCargoExtend::CmdGrpCargoExtend(){
	//CommandGroup::AddSequential(new CmdCargoTilt(true));
	CommandGroup::AddSequential(new CmdCargoExtendTime(3,0.75)); 
	CommandGroup::AddSequential(new CmdCargoTilt(false));
}



