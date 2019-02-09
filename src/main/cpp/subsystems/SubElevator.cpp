/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "subsystems/SubElevator.h"

#include "RobotMap.h"

SubElevator::SubElevator() : frc::Subsystem("SubElevator") {}

void SubElevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Resets the position on the Talon to the home position
void SubElevator::ResetHomePosition() {
    // Reset the postion when bottom limit switch is made
    elevatorDrive->SetSelectedSensorPosition(ELEVATOR_RESET_HOME_POS,0,0);

}

// Used for testing elevator movements
void SubElevator::MoveElevatorToPosition(double position) {
    // Raise elevator to requested position
    elevatorDrive->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, position);
}

// Configure the elevator Talon
void SubElevator::Configure() {
    // Configure the setting for the PID etc.
    elevatorDrive->Config_kF(0,ELEVATOR_KF_0,0);
    elevatorDrive->Config_kP(0,ELEVATOR_KP_0,0);
    elevatorDrive->Config_kI(0,ELEVATOR_KI_0,0);
    elevatorDrive->Config_kD(0,ELEVATOR_KD_0,0);

    // Configure the cruise velocity and the acceleration 
    elevatorDrive->ConfigMotionCruiseVelocity(ELEVATOR_CRUISE_VELOCITY,0);
    elevatorDrive->ConfigMotionAcceleration(ELEVATOR_ACCELERATION,0);

    // Configure the hard limit switches of the talon
    elevatorDrive->ConfigReverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector,LimitSwitchNormal_NormallyOpen,0);
    elevatorDrive->ConfigForwardLimitSwitchSource(LimitSwitchSource_FeedbackConnector,LimitSwitchNormal_NormallyOpen,0);
 
    // Set the talon soft limits and enable limits
    elevatorDrive->ConfigForwardSoftLimitThreshold(ELEVATOR_TOP_SOFT_LIMIT,0);
    elevatorDrive->ConfigReverseSoftLimitThreshold(ELEVATOR_BOT_SOFT_LIMIT,0);
    elevatorDrive->ConfigForwardSoftLimitEnable(ELEVATOR_SOFT_LIMITS_ENABLE,0);
    elevatorDrive->ConfigReverseSoftLimitEnable(ELEVATOR_SOFT_LIMITS_ENABLE,0);

    // This shouldn't be here.  But it is here for now, setting the level positions and index
    SubElevator::SetLevelPositionTarget(ELEVATOR_HOME, ELEVATOR_LEVEL_POS_HOME);
    SubElevator::SetLevelPositionTarget(ELEVATOR_BTM_HATCH, ELEVATOR_LEVEL_BTM_POS_HATCH);
    SubElevator::SetLevelPositionTarget(ELEVATOR_BTM_BALL, ELEVATOR_LEVEL_BTM_POS_BALL);
    SubElevator::SetLevelPositionTarget(ELEVATOR_MID_HATCH, ELEVATOR_LEVEL_MID_POS_HATCH);
    SubElevator::SetLevelPositionTarget(ELEVATOR_MID_BALL, ELEVATOR_LEVEL_MID_POS_BALL);   
    SubElevator::SetLevelPositionTarget(ELEVATOR_TOP_HATCH, ELEVATOR_LEVEL_TOP_POS_HATCH);
    SubElevator::SetLevelPositionTarget(ELEVATOR_TOP_BALL, ELEVATOR_LEVEL_TOP_POS_BALL);

}

// get the current elevator position
int SubElevator::GetPosition() {
    return elevatorDrive->GetSelectedSensorPosition(0);
}

// Sets the position location level and position target
void SubElevator::SetLevelPositionTarget(int index, int position) {
    if((0 <= index) && (index <= ELEVATOR_LEVELS)){
        a_iLevelPositions[index] = position;
    }

}

// Sets the level of the elevator
void SubElevator::SetLevel(int level) {
    
    
    m_iActiveLevel = level;
}

// Gets the status of the forward limit switch
int SubElevator::GetForwardLimitSwitch() {
    return elevatorDrive->GetSensorCollection().IsFwdLimitSwitchClosed();
}

// Gets the status of the reverse limit switch
int SubElevator::GetReverseLimitSwitch() {
    return elevatorDrive->GetSensorCollection().IsRevLimitSwitchClosed();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
