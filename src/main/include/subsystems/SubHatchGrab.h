/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once

#include "RobotMap.h"
#include "frc/Compressor.h"
#include "subsystems/SubPCM.h"
#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>

class SubHatchGrab : public frc::Subsystem {
public:
  SubHatchGrab();
  void InitDefaultCommand() override;
  void Set(bool state);
  bool GetHatchPos();
  void Extend4(bool state);
  void Extend7(bool state);
  bool hatchIsOn();

private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  frc::Solenoid *hatchReleaseSolenoid =
      new frc::Solenoid(PCM_TOP, TOP_HATCH_GRABBER);

  frc::Solenoid *hatchExtend4 = new frc::Solenoid(PCM_TOP, TOP_HATCH_EXT_4);
  frc::Solenoid *hatchExtend7 = new frc::Solenoid(PCM_TOP, TOP_HATCH_EXT_7);

  frc::DigitalInput *hatchDetectHallEffect =
      new frc::DigitalInput(HATCH_HALL_EFFECT);

  bool m_bEngageState = 0;
};
