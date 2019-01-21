/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include "frc/Compressor.h"
#include "RobotMap.h"

class SubPCM : public frc::Subsystem {
 public:

  SubPCM();
  void InitDefaultCommand() override;
  void Configure();
  // Example solenoid
  frc::Solenoid* exampleSolenoid = new frc::Solenoid(PCM_BOTTOM, SOLENOID_0);

 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  frc::Compressor* compressor = new frc::Compressor(0);
  // frc::Solenoid exampleSolenoid {1};
  
  
};
