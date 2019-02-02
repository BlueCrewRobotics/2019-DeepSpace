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
    // Raise elevator to requested postion
    elevatorDrive->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, position);
}

void SubElevator::SetPositionSoftLimits(double top, double bottom) {
    // Set the talon soft limits
    // Maybe throw this in Configure fuction
}

void SubElevator::ConfigureHardLimits() {
    // Configure the hard limit switches of the talon
    // Maybe throw this in Configure fuction
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

// Put methods for controlling this subsystem
// here. Call these from Commands.
