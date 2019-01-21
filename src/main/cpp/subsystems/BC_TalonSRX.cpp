
#include "RobotMap.h"
#include "subsystems/BC_TalonSRX.h"
#include <ctre/Phoenix.h>



BC_TalonSRX::BC_TalonSRX(int device)  {

  BC_TalonSRX::ptr_talonSRX = new TalonSRX( device );

}

void BC_TalonSRX::Set(double speed) {
    speed = speed*VELOCITY_SP_MAX_LG;
    ptr_talonSRX->Set(ControlMode::Velocity, speed);
    m_iSpeed = speed;
}

void BC_TalonSRX::PIDWrite(double output) {

}

double BC_TalonSRX::Get() const {
    return m_iSpeed;
}

void BC_TalonSRX::SetInverted(bool isInverted) {
    ptr_talonSRX->SetInverted(isInverted);
}

bool BC_TalonSRX::GetInverted() const {
    return ptr_talonSRX->GetInverted();
}

void BC_TalonSRX::Disable() {
    ptr_talonSRX->SetNeutralMode(NeutralMode::Coast);
}

void BC_TalonSRX::StopMotor() {
    ptr_talonSRX->SetNeutralMode(NeutralMode::Brake);
}