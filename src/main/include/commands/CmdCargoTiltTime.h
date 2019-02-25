/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once

#include <frc/commands/Command.h>

class CmdCargoTiltTime : public frc::Command {
public:
  CmdCargoTiltTime(bool state, double time);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

private:
  bool m_bState = 0;
  double m_dTime = 0;
};
