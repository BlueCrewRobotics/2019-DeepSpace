

#include "RobotMap.h"
#include "subsystems/BC_VictorSPX.h"
#include <ctre/Phoenix.h>



BC_VictorSPX::BC_VictorSPX(int device)  {

  BC_VictorSPX::ptr_VictorSPX = new VictorSPX( device );

}

void BC_VictorSPX::Set(double speed) {
    speed = speed*VELOCITY_SP_MAX_LG;
    ptr_VictorSPX->Set(ControlMode::Velocity, speed);
    m_iSpeed = speed;
}

void BC_VictorSPX::PIDWrite(double output) {

}

double BC_VictorSPX::Get() const {
    return m_iSpeed;
}

void BC_VictorSPX::SetInverted(bool isInverted) {
    ptr_VictorSPX->SetInverted(isInverted);
}

bool BC_VictorSPX::GetInverted() const {
    return ptr_VictorSPX->GetInverted();
}

void BC_VictorSPX::Disable() {
    ptr_VictorSPX->SetNeutralMode(NeutralMode::Coast);
}

void BC_VictorSPX::StopMotor() {
    ptr_VictorSPX->SetNeutralMode(NeutralMode::Brake);
}