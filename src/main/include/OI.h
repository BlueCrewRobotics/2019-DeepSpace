/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once

#include <frc/WPILib.h>
#include "commands/CmdSwitchGear.h"
#include "commands/CmdElevatorUpOne.h"
#include "commands/CmdElevatorUpTop.h"
#include "commands/CmdElevatorDownOne.h"
#include "commands/CmdElevatorDownBottom.h"
#include "commands/CmdCargoClampClose.h"
#include "commands/CmdCargoClampOpen.h"
#include "commands/CmdCargoTilt.h"

#include "RobotMap.h"

class OI {
	public:
		OI();

		// Setup driver controller 
		frc::Joystick* driverController = new frc::Joystick(DRIVER_CONTROLLER);
		// Setup buttons on the driver controller, change the name to fit the command
		frc::JoystickButton* driverController_button_a = new frc::JoystickButton(driverController, BUTTON_A); // Not Used
		frc::JoystickButton* driverController_button_b = new frc::JoystickButton(driverController, BUTTON_B); // Not Used
		frc::JoystickButton* driverController_button_x = new frc::JoystickButton(driverController, BUTTON_X); // Not Used
		frc::JoystickButton* driverController_button_y = new frc::JoystickButton(driverController, BUTTON_Y); // Not Used
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
		frc::JoystickButton* auxController_button_rbump = new frc::JoystickButton(auxController, BUTTON_R_BUMP); // Toggle Swiss Army Knife
		frc::JoystickButton* auxController_button_select = new frc::JoystickButton(auxController, BUTTON_SELECT); // Not Used
		frc::JoystickButton* auxController_button_start = new frc::JoystickButton(auxController, BUTTON_START); // Not Used
		frc::JoystickButton* auxController_button_l3 = new frc::JoystickButton(auxController, BUTTON_L3); // Not Used
		frc::JoystickButton* auxController_button_r3 = new frc::JoystickButton(auxController, BUTTON_R3); // Not Used
		// LEFT TRIGGER // Push out Cargo
		// RIGHT TRIGGER // Pull in Cargo
		
		// LEFT STICK UP // Push Swiss Army Knife out 1 stage
		// LEFT STICK LEFT // Push Swiss Army Knife out all the way
		// LEFT STICK DOWN // Pull Swiss Army Knife in 1 stage
		// LEFT STICK RIGHT // Pull Swiss Army Knife in all the way
		
		// RIGHT STICK UP // Move Elevator up 1 stage
		// RIGHT STICK RIGHT // Move Elevator up all the way
		// RIGHT STICK DOWN // Move Elevator down 1 stage
		// RIGHT STICK LEFT // Move Elevator down all the way


};
