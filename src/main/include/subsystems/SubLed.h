/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once

#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>

class SubLed : public frc::Subsystem {
public:
  SubLed();
  void InitDefaultCommand() override;
  void setLedColor(float colorCode);

private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  //
  // The Rev Blinkin controller uses the same interface as the
  // Rev Spark Motor controller
  frc::Spark *ledController = new frc::Spark(4);
};
