/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "OI.h"


OI::OI() {
  // Process operator interface input here.

  driverController_button_rbump->ToggleWhenPressed(new CmdSwitchGear());

  auxController_button_b->WhileActive(new CmdCargoClampOpen());
  auxController_button_b->WhenReleased(new CmdCargoClampClose());

  auxController_button_a->ToggleWhenPressed(new CmdCargoTilt());
}
