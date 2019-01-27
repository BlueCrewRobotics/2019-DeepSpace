/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/WPILib.h>
#include "commands/CmdSwitchGear.h"
#include "RobotMap.h"

class OI {
 public:
  OI();

  // Setup driver controller 
  frc::Joystick* driverController = new frc::Joystick(DRIVER_CONTROLLER);
  // Setup buttons on the driver controller, change the name to fit the command
  frc::JoystickButton* driverController_button_a = new frc::JoystickButton(driverController, BUTTON_A);
  frc::JoystickButton* driverController_button_b = new frc::JoystickButton(driverController, BUTTON_B);
  frc::JoystickButton* driverController_button_x = new frc::JoystickButton(driverController, BUTTON_X);
  frc::JoystickButton* driverController_button_y = new frc::JoystickButton(driverController, BUTTON_Y);
  frc::JoystickButton* driverController_button_lbump = new frc::JoystickButton(driverController, BUTTON_L_BUMP);
  frc::JoystickButton* driverController_button_rbump = new frc::JoystickButton(driverController, BUTTON_R_BUMP);
  frc::JoystickButton* driverController_button_select = new frc::JoystickButton(driverController, BUTTON_SELECT);
  frc::JoystickButton* driverController_button_start = new frc::JoystickButton(driverController, BUTTON_START);
  frc::JoystickButton* driverController_button_l3 = new frc::JoystickButton(driverController, BUTTON_L3);
  frc::JoystickButton* driverController_button_r3 = new frc::JoystickButton(driverController, BUTTON_R3);

  // Setup aux controller
  frc::Joystick* auxController = new frc::Joystick(AUX_CONTROLLER);
  // Setup buttons on the aux controller, change the names to fit the command 
  frc::JoystickButton* auxController_button_a = new frc::JoystickButton(auxController, BUTTON_A);
  frc::JoystickButton* auxController_button_b = new frc::JoystickButton(auxController, BUTTON_B);
  frc::JoystickButton* auxController_button_x = new frc::JoystickButton(auxController, BUTTON_X);
  frc::JoystickButton* auxController_button_y = new frc::JoystickButton(auxController, BUTTON_Y);
  frc::JoystickButton* auxController_button_lbump = new frc::JoystickButton(auxController, BUTTON_L_BUMP);
  frc::JoystickButton* auxController_button_rbump = new frc::JoystickButton(auxController, BUTTON_R_BUMP);
  frc::JoystickButton* auxController_button_select = new frc::JoystickButton(auxController, BUTTON_SELECT);
  frc::JoystickButton* auxController_button_start = new frc::JoystickButton(auxController, BUTTON_START);
  frc::JoystickButton* auxController_button_l3 = new frc::JoystickButton(auxController, BUTTON_L3);
  frc::JoystickButton* auxController_button_r3 = new frc::JoystickButton(auxController, BUTTON_R3);

};
