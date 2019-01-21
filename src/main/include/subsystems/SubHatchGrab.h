#pragma once
#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"

class SubHatchGrab: public frc::Subsystem{
	public:
					SubHatchGrab();
					void Configure();
					void Grab();
					void Deploy();

	public:
					frc::DoubleSolenoid *armPTC = new frc::DoubleSolenoid(ARM_GRABBER_FORWARD, ARM_GRABBER_REVERSE);
};
