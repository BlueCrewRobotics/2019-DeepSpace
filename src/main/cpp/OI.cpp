/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "OI.h"
#include "Robot.h"
#include <iostream>



OI::OI() {

  // Process operator interface input here.
  
  // Call switch gear command
  driverController_button_rbump->ToggleWhenPressed(new CmdSwitchGear());

  // Elevator testing
  //driverController_button_a->WhileActive(new CmdElevatorTestDown());
  //driverController_button_a->WhenReleased(new CmdElevatorTestStop());
  //driverController_button_y->WhileActive(new CmdElevatorTestUp());
  //driverController_button_y->WhenReleased(new CmdElevatorTestStop());
  // Maybe make a hold position on test if needed 

  

//auxController_button_a->ToggleWhenPressed(new CmdCargoTilt());

// Cargo intake, shoot and stop
/*  if( auxController->GetRawAxis(AXIS_R_TRIG) > 0.1){
      // Call Cargo Intake CommandCmdCargoIntake
      cargoIntakeTrigger->Set(true);
  } else {
      cargoIntakeTrigger->Set(false);
  }

  if( auxController->GetRawAxis(AXIS_L_TRIG) > 0.1){
      // Call Cargo Shoot Command
      cargoShootTrigger->Set(true);
  } else {
      cargoShootTrigger->Set(false);
  }
  
  if( cargoIntakeTrigger->Get() == false && cargoShootTrigger->Get() == false){
      cargoStop->WhenInactive(new CmdCargoStop());
  } 

  cargoIntakeTrigger->WhileActive(new CmdCargoIntake());
  cargoShootTrigger->WhileActive(new CmdCargoShoot());

  cargoTiltTrigger->WhileActive(new CmdCargoTilt());
*/  

  //auxController_button_lbump->ToggleWhenPressed(new GrabHatch());
  
  // Reset elevator home position to zero.  Must be at the home position all the way down
  auxController_button_start->ToggleWhenPressed(new CmdElevatorResetHome());


  // Hatch return to home position
  auxController_button_x->ToggleWhenPressed(new CmdHatchCargoNeutral());
  
  // Hatch extend to mid position
  auxController_button_y->ToggleWhenPressed(new CmdHatchCargoSwitch());
  
  // Cargo extend to out position
  // auxController_button_y->ToggleWhenPressed(new CmdCargoExtend(3));

  /*
  if( Robot::m_subCargoGrab.m_bHatchCargoCurrent == 0){
    
    // Extend Cargo
    auxController_button_rbump->WhenPressed(new CmdCargoExtend(3));
    auxController_button_rbump->WhenReleased(new CmdCargoExtend(1));

    // Opens and Closes Cargo Clamp
    auxController_button_lbump->WhenPressed(new CmdCargoClampOpen());
    auxController_button_lbump->WhenReleased(new CmdCargoClampClose());

  }

  if( Robot::m_oi.m_bHatchCargoCurrent == 1){
    
    // Hatch extend to deploy position while button is held return when released
    auxController_button_rbump->WhenPressed(new CmdHatchExt(2));
    auxController_button_rbump->WhenReleased(new CmdHatchExt(1));   

    // Hatch grab and release
    auxController_button_lbump->WhenPressed(new CmdHatchRelease());
    auxController_button_lbump->WhenReleased(new CmdHatchGrab());  
  }
*/
  
}

void OI::SwitchControl(){
  if( Robot::m_subCargoGrab.m_bHatchCargoCurrent == 0){
    
    // Extend Cargo
    auxController_button_rbump->WhenPressed(new CmdCargoExtend(3));
    auxController_button_rbump->WhenReleased(new CmdCargoExtend(1));

    // Opens and Closes Cargo Clamp
    auxController_button_lbump->WhenPressed(new CmdCargoClampOpen());
    auxController_button_lbump->WhenReleased(new CmdCargoClampClose());

  }

  if( Robot::m_oi.m_bHatchCargoCurrent == 1){
    
    // Hatch extend to deploy position while button is held return when released
    auxController_button_rbump->WhenPressed(new CmdHatchExt(2));
    auxController_button_rbump->WhenReleased(new CmdHatchExt(1));   

    // Hatch grab and release
    auxController_button_lbump->WhenPressed(new CmdHatchRelease());
    auxController_button_lbump->WhenReleased(new CmdHatchGrab());  
  }
}