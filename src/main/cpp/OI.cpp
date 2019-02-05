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
  
  
}
