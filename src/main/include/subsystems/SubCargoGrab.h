/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once

#include "BC_VictorSPX.h"
#include "RobotMap.h"
#include "subsystems/SubPCM.h"
#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>
// #include "Robot.h"

class SubCargoGrab : public frc::Subsystem {
public:
  SubCargoGrab();
  void InitDefaultCommand() override;
  void Intake(double leftspeed, double rightspeed);
  void Shoot(double leftspeed, double rightspeed);
  void Stop();
  void ClampSet(bool state);
  void SetTiltPos(bool state);
  bool GetTiltPos();
  void SetExtend5(bool state);
  bool GetExtend5();
  void SetExtend7(bool state);
  bool GetExtend7();

private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  frc::Solenoid *cargoExtend5 = new frc::Solenoid(PCM_TOP, TOP_CARGO_EXT_5);
  frc::Solenoid *cargoExtend7 = new frc::Solenoid(PCM_TOP, TOP_CARGO_EXT_7);

  frc::Solenoid *clampSolenoid = new frc::Solenoid(PCM_TOP, TOP_CLAMP_SOLENOID);

  frc::Solenoid *tiltPositionSolenoid =
      new frc::Solenoid(PCM_TOP, TOP_CARGO_TILT);

  VictorSPX *leftIntakeMotor = new VictorSPX(CARGO_LEFT_CAN_ADDR);
  VictorSPX *rightIntakeMotor = new VictorSPX(CARGO_RIGHT_CAN_ADDR);

  bool m_bTiltPos = 0;
  bool m_bExtend5Pos = 0;
  bool m_bExtend7Pos = 0;
};
