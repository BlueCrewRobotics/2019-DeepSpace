/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once

#include "subsystems/SubElevator.h"
#include <frc/commands/Command.h>

class CmdElevatorTestDown : public frc::Command {
public:
  CmdElevatorTestDown();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};