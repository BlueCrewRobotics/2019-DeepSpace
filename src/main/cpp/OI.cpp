/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "OI.h"


OI::OI() {
  // Process operator interface input here.

  driverController_button_rbump->ToggleWhenPressed(new CmdSwitchGear());
  
}
