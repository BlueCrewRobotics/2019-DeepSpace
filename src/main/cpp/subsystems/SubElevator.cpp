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

void SubElevator::ResetPostion() {
    // Reset the postion when bottom limit switch is made
    elevatorDrive->SetSelectedSensorPosition(ELEVATOR_RESET_POSITION,0,0);

}

void SubElevator::RaiseElevatorToPosition(double position) {
    // Raise elevator to requested position
    elevatorDrive->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, position);
}

void SubElevator::SetPositionSoftLimits(double top, double bottom) {
    // Set the talon soft limits
    // Maybe throw this in Configure function
    elevatorDrive->ConfigForwardSoftLimitThreshold(ELEVATOR_TOP_SOFT_LIMIT,0);
    elevatorDrive->ConfigReverseSoftLimitThreshold(ELEVATOR_BOT_SOFT_LIMIT,0);

    elevatorDrive->ConfigForwardSoftLimitEnable(ELEVATOR_SOFT_LIMITS_ENABLE,0);
    elevatorDrive->ConfigReverseSoftLimitEnable(ELEVATOR_SOFT_LIMITS_ENABLE,0);
    
}

void SubElevator::ConfigureHardLimits() {
    // Configure the hard limit switches of the talon
    // Maybe throw this in Configure function
    elevatorDrive->ConfigReverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector,LimitSwitchNormal_NormallyOpen,0);
}

void SubElevator::Configure() {
    // Configure the setting for the PID etc.
    elevatorDrive->Config_kF(0,ELEVATOR_KF_0,0);
    elevatorDrive->Config_kP(0,ELEVATOR_KP_0,0);
    elevatorDrive->Config_kI(0,ELEVATOR_KI_0,0);
    elevatorDrive->Config_kD(0,ELEVATOR_KD_0,0);
 
    elevatorDrive->ConfigMotionCruiseVelocity(ELEVATOR_CRUISE_VELOCITY,0);
    elevatorDrive->ConfigMotionAcceleration(ELEVATOR_ACCELERATION,0);

}

int SubElevator::GetPosition() {
    return elevatorDrive->GetSelectedSensorPosition(0);
}

void SubElevator::SetLevelPositionTarget(int position, int index) {
    if((0 <= index) && (index <= ELEVATOR_LEVELS)){
        a_iLevelPositions[index] = position;
    }

}

void SubElevator::SetLevel(int level) {
    m_iActiveLevel = level;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
