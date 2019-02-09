/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "OI.h"


OI::OI() {
  // Process operator interface input here.

  driverController_button_rbump->ToggleWhenPressed(new CmdSwitchGear());


  // *** Elevator command calls ***
  if( auxController->GetRawAxis(AXIS_RX) > 0.1){
      // Call elevator up top command
      new CmdElevatorUpTop();

  }
  if( auxController->GetRawAxis(AXIS_RY) > 0.1){
      // Call elevator up one level command
      new CmdElevatorUpOne();

  }
  if( auxController->GetRawAxis(AXIS_RX) < -0.1){
      // Call elevator down bottom command
      new CmdElevatorDownBottom();

  }
  if( auxController->GetRawAxis(AXIS_RY) < -0.1){
      // Call elevator down one level command
      new CmdElevatorDownOne();

  }
  
  
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
}
