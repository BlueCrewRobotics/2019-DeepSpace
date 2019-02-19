/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once

#include <frc/WPILib.h>
#include "commands/CmdSwitchGear.h"
#include "commands/CmdElevator.h"
#include "commands/CmdCargoClampClose.h"
#include "commands/CmdCargoClampOpen.h"
#include "commands/CmdCargoTilt.h"
#include "commands/CmdCargoIntake.h"
#include "commands/CmdCargoShoot.h"
#include "commands/GrabHatch.h"
#include "commands/CmdElevatorTestDown.h"
#include "commands/CmdElevatorTestUp.h"
#include "commands/CmdElevatorTestStop.h"
#include "commands/CmdElevatorResetHome.h"
#include "commands/CmdCargoStop.h"
#include "commands/CmdHatchExt.h"
#include "commands/CmdHatchGrab.h"
#include "commands/CmdHatchRelease.h"
#include "commands/CmdCargoExtend.h"
#include "commands/CmdHatchCargoSwitch.h"
#include "commands/CmdHatchCargoNeutral.h"
#include "commands/CmdGrpCargoExtend.h"
#include "commands/CmdGrpCargoRetract.h"

#include "RobotMap.h"
#include "common/BC_Switch.h"


class OI {
	public:
		OI();

		void PollController();
		void SwitchControl();
		void HatchControl();
		bool m_bHatchCargoCurrent;
		bool m_bCargoExtendToggle = 0;
		bool m_bSelector = false;

		BC_Switch* m_cargoIntakeSw = new BC_Switch(DIGITAL_INPUT_0);


		// Setup driver controller 
		frc::Joystick* driverController = new frc::Joystick(DRIVER_CONTROLLER);
		// Setup buttons on the driver controller, change the name to fit the command
		frc::JoystickButton* driverController_button_a = new frc::JoystickButton(driverController, BUTTON_A); // Manual Elevator
		frc::JoystickButton* driverController_button_b = new frc::JoystickButton(driverController, BUTTON_B); // Not Used
		frc::JoystickButton* driverController_button_x = new frc::JoystickButton(driverController, BUTTON_X); // Not Used
		frc::JoystickButton* driverController_button_y = new frc::JoystickButton(driverController, BUTTON_Y); // Manual Elevator 
		frc::JoystickButton* driverController_button_lbump = new frc::JoystickButton(driverController, BUTTON_L_BUMP); // Not Used
		frc::JoystickButton* driverController_button_rbump = new frc::JoystickButton(driverController, BUTTON_R_BUMP);  // Used in gear shifting
		frc::JoystickButton* driverController_button_select = new frc::JoystickButton(driverController, BUTTON_SELECT); // Lineup button
		frc::JoystickButton* driverController_button_start = new frc::JoystickButton(driverController, BUTTON_START); // Not Used
		frc::JoystickButton* driverController_button_l3 = new frc::JoystickButton(driverController, BUTTON_L3); // Not Used
		frc::JoystickButton* driverController_button_r3 = new frc::JoystickButton(driverController, BUTTON_R3); // Not Used
		// LEFT TRIGGER // Drive Backwards
		// RIGHT TRIGGER // Drive Forwards
		// LEFT STICK LEFT // Turn Left
		// LEFT STICK RIGHT // Turn Right

		// Setup aux controller
		frc::Joystick* auxController = new frc::Joystick(AUX_CONTROLLER);
		// Setup buttons on the aux controller, change the names to fit the command 
		frc::JoystickButton* auxController_button_a = new frc::JoystickButton(auxController, BUTTON_A); // Tilt Cargo Grab
		frc::JoystickButton* auxController_button_b = new frc::JoystickButton(auxController, BUTTON_B); // Clamp/UnClamp Cargo claw
		frc::JoystickButton* auxController_button_x = new frc::JoystickButton(auxController, BUTTON_X); // Not Used
		frc::JoystickButton* auxController_button_y = new frc::JoystickButton(auxController, BUTTON_Y); // Not Used
		frc::JoystickButton* auxController_button_lbump = new frc::JoystickButton(auxController, BUTTON_L_BUMP); // Grab/Let go of Hatch panel
		frc::JoystickButton* auxController_button_rbump = new frc::JoystickButton(auxController, BUTTON_R_BUMP); // Engage either Hatch Panel Grabber or Cargo Grabber (MUST HAVE A BIT THAT SPECIFIES WHICH IS ENGAGED FOR THE ELEVATOR)
		frc::JoystickButton* auxController_button_select = new frc::JoystickButton(auxController, BUTTON_SELECT); // Not Used
		frc::JoystickButton* auxController_button_start = new frc::JoystickButton(auxController, BUTTON_START); // Reset elevator home position
		frc::JoystickButton* auxController_button_l3 = new frc::JoystickButton(auxController, BUTTON_L3); // Not Used
		frc::JoystickButton* auxController_button_r3 = new frc::JoystickButton(auxController, BUTTON_R3); // Not Used
		 // LEFT TRIGGER // Push out Cargo
		 // RIGHT TRIGGER // Pull in Cargo

		// Internal buttons used as triggers for automation.  See OI::Checker for pressing and releasing buttons
		frc::InternalButton* cargoIntake = new frc::InternalButton();
		frc::InternalButton* cargoShoot = new frc::InternalButton();
		frc::InternalButton* cargoStop = new frc::InternalButton();
		frc::InternalButton* elevCargoTilt = new frc::InternalButton();
		
		frc::InternalButton* cargoExtend = new frc::InternalButton();
		frc::InternalButton* cargoClamp = new frc::InternalButton();

		// Hatch Panel Internal Buttons
		frc::InternalButton* hatchExtend = new frc::InternalButton();
		frc::InternalButton* hatchGrabOrRelease = new frc::InternalButton();



		//frc::InternalButton* detectHatch = new frc::InternalButton();
		

		// D PAD UP // Move Elevator up 1 stage
		// D PAD DOWN // Move Elevator down 1 stage
	


};
