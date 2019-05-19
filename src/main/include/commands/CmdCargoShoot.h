/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once

#include <frc/commands/Command.h>
#include "frc/WPILib.h"

class CmdCargoShoot : public frc::Command {
public:
  CmdCargoShoot();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
  frc::DigitalInput *bumpSwitch = new frc::DigitalInput(4);
};
