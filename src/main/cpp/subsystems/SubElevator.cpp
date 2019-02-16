/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "subsystems/SubElevator.h"
#include "commands/CmdElevator.h"

#include "RobotMap.h"

SubElevator::SubElevator() : frc::Subsystem("SubElevator") {}

void SubElevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new CmdElevator());
}

// Resets the position on the Talon to the home position
void SubElevator::ResetHomePosition() {
    // Reset the postion when bottom limit switch is made
    elevatorDrive->SetSelectedSensorPosition(ELEVATOR_RESET_HOME_POS,0,0);

}

// Used for testing elevator movements
void SubElevator::MoveElevatorToPosition(int position) {
    // Raise elevator to requested position
    int currentPosition;
    int moveDirection;

    currentPosition = elevatorDrive->GetSensorCollection().GetQuadraturePosition();
    moveDirection = position - currentPosition;
    
    if((elevatorDrive->GetSensorCollection().IsFwdLimitSwitchClosed() == 1) && (moveDirection > 0))  {
        elevatorDrive->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, position);
    }
    else {
        if((elevatorDrive->GetSensorCollection().IsRevLimitSwitchClosed() ==1) && (moveDirection < 0)) {
            elevatorDrive->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, position);
        }
    }

}

// Servo to the requested position
void SubElevator::ServoToPosition(double position) {
    elevatorDrive->Set(ControlMode::Position,position);
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

    elevatorDrive->ConfigSelectedFeedbackSensor(QuadEncoder,0,0);
	elevatorDrive->ConfigSelectedFeedbackSensor(QuadEncoder,0,1);
	elevatorDrive->SetSensorPhase(true);
    elevatorDrive->SetInverted(InvertType::InvertMotorOutput);

    elevatorDrive->ConfigPeakCurrentDuration(1,0);
    elevatorDrive->ConfigPeakCurrentLimit(15,0);
    elevatorDrive->ConfigContinuousCurrentLimit(15,0);
    elevatorDrive->EnableCurrentLimit(true);

    elevatorDrive->ConfigClosedloopRamp(0.25,0);

    // This shouldn't be here.  But it is here for now, setting the level positions and index
    //SubElevator::SetLevelPositionTarget(ELEVATOR_HOME, ELEVATOR_LEVEL_POS_HOME);
    //SubElevator::SetLevelPositionTarget(ELEVATOR_BTM_HATCH, ELEVATOR_LEVEL_BTM_POS_HATCH);
    //SubElevator::SetLevelPositionTarget(ELEVATOR_BTM_BALL, ELEVATOR_LEVEL_BTM_POS_BALL);
    //SubElevator::SetLevelPositionTarget(ELEVATOR_MID_HATCH, ELEVATOR_LEVEL_MID_POS_HATCH);
    //SubElevator::SetLevelPositionTarget(ELEVATOR_MID_BALL, ELEVATOR_LEVEL_MID_POS_BALL);   
    //SubElevator::SetLevelPositionTarget(ELEVATOR_TOP_HATCH, ELEVATOR_LEVEL_TOP_POS_HATCH);
    //SubElevator::SetLevelPositionTarget(ELEVATOR_TOP_BALL, ELEVATOR_LEVEL_TOP_POS_BALL);

    SubElevator::SetBallPositionTarget(ELEV_BALL_GRAB, ELEV_BALL_GRAB_POS);
    SubElevator::SetBallPositionTarget(ELEV_BALL_ROCKET_BTM, ELEV_BALL_ROCKET_BTM_POS);
    SubElevator::SetBallPositionTarget(ELEV_BALL_CONTAINER, ELEV_BALL_CONTAINER_POS);
    SubElevator::SetBallPositionTarget(ELEV_BALL_ROCKET_MID, ELEV_BALL_ROCKET_MID_POS);
    SubElevator::SetBallPositionTarget(ELEV_BALL_ROCKET_TOP, ELEV_BALL_ROCKET_TOP_POS);

    SubElevator::SetHatchPositionTarget(ELEV_HATCH_ROCKET_BTM, ELEV_HATCH_ROCKET_BTM_POS);
    SubElevator::SetHatchPositionTarget(ELEV_HATCH_ROCKET_MID, ELEV_HATCH_ROCKET_MID_POS);
    SubElevator::SetHatchPositionTarget(ELEV_HATCH_ROCKET_TOP, ELEV_HATCH_ROCKET_TOP_POS);
}

// get the current elevator position
int SubElevator::GetPosition() {
    return elevatorDrive->GetSelectedSensorPosition(0);
}

// Sets the position location level and position target
//void SubElevator::SetLevelPositionTarget(int index, int position) {
//    if((0 <= index) && (index <= ELEVATOR_LEVELS)){
//        a_iLevelPositions[index] = position;
//    }

//}

// Sets the position location position target for ball deploy
void SubElevator::SetBallPositionTarget(int index, int position) {
    if((0 <= index) && (index <= ELEVATOR_BALL_LEVELS)){
        a_iBallLevelPos[index] = position;
    }

}

// Sets the position location position target for hatch deploy
void SubElevator::SetHatchPositionTarget(int index, int position) {
    if((0 <= index) && (index <= ELEVATOR_HATCH_LEVELS)){
        a_iHatchLevelPos[index] = position;
    }

}

// Sets the level of the elevator
//void SubElevator::SetLevel(int level) {  
//    m_iActiveLevel = level;
//}

// Sets the level of the ball deploy
void SubElevator::SetBallLevel(int level) {  
    m_iBallLevel = level;
}

// Sets the level of the hatch deploy
void SubElevator::SetHatchLevel(int level) {  
    m_iHatchLevel = level;
}

// Get level of elevator
//int SubElevator::GetLevel() {
//    return m_iActiveLevel;
//}

// Get level of elevator
int SubElevator::GetBallLevel() {
    return m_iBallLevel;
}

// Get level of elevator
int SubElevator::GetHatchLevel() {
    return m_iHatchLevel;
}

// Gets the status of the forward limit switch
int SubElevator::GetUpLimitSwitch() {
    return elevatorDrive->GetSensorCollection().IsFwdLimitSwitchClosed();
}

// Gets the status of the reverse limit switch
int SubElevator::GetDownLimitSwitch() {
    return elevatorDrive->GetSensorCollection().IsRevLimitSwitchClosed();
}

// Drive elevator
void SubElevator::DriveElevator(double output){
    elevatorDrive->Set(ControlMode::PercentOutput,output);
}

// Get PID error
int SubElevator::GetPIDerror() {
    return elevatorDrive->GetClosedLoopError();
}

// Get PID target
double SubElevator::GetPIDtarget() {
    return elevatorDrive->GetClosedLoopTarget();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
