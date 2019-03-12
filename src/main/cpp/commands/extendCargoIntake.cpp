#include "commands/extendCargoIntake.h"

extendCargoIntake::extendCargoIntake() {
  CommandGroup::AddSequential(new CmdCargoTilt(true));
  CommandGroup::AddParallel(new CmdCargoExtend(0)); // Needs to change (0)
  CommandGroup::AddSequential(new CmdCargoTilt(false));
}
