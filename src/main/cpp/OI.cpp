/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "OI.h"


OI::OI() {
  // Process operator interface input here.
  
  // Call switch gear command
  driverController_button_rbump->ToggleWhenPressed(new CmdSwitchGear());



  // Elevator testing
  driverController_button_a->WhileActive(new CmdElevatorTestDown());
  driverController_button_a->WhenReleased(new CmdElevatorTestStop());
  driverController_button_y->WhileActive(new CmdElevatorTestUp());
  driverController_button_y->WhenReleased(new CmdElevatorTestStop());

  // Reset elevator home position to zero.  Must be at the home position all the way down
  auxController_button_start->ToggleWhenPressed(new CmdElevatorResetHome());

  
  
  auxController_button_b->WhileActive(new CmdCargoClampOpen());
  auxController_button_b->WhenReleased(new CmdCargoClampClose());

  auxController_button_a->ToggleWhenPressed(new CmdCargoTilt());

  if( auxController->GetRawAxis(AXIS_R_TRIG) > 0.1){
      // Call Cargo Intake Command
      new CmdCargoIntake();
  } else if( auxController->GetRawAxis(AXIS_L_TRIG) > 0.1){
      // Call Cargo Shoot Command
      new CmdCargoShoot();
  }

  auxController_button_lbump->ToggleWhenPressed(new GrabHatch());
}
