/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once

#include <frc/commands/Command.h>

class CmdCargoExtendTime : public frc::Command {
public:
  CmdCargoExtendTime(int position, double time);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

private:
  int m_iPosition;
  double m_dTime;
};
