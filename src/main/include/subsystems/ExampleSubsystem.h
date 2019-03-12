/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once

#include <frc/commands/Subsystem.h>

class ExampleSubsystem : public frc::Subsystem {
public:
  ExampleSubsystem();
  void InitDefaultCommand() override;

private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
};
