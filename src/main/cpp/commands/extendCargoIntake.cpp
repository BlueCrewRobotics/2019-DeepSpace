#include "commands/extendCargoIntake.h"

extendCargoIntake::extendCargoIntake(){
	CommandGroup::AddSequential(new CmdCargoTilt());
	CommandGroup::AddParallel(new CmdCargoExtend5());
	CommandGroup::AddParallel(new CmdCargoExtend7());
	CommandGroup::AddSequential(new CmdCargoTilt());
}

