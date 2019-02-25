/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "frc/WPILib.h"

class BC_Switch {

public:
  BC_Switch(int input);
  bool GetSwitchState();

private:
  frc::DigitalInput *ptr_digitalInput = nullptr;
  frc::Counter *ptr_Counter = nullptr;
};