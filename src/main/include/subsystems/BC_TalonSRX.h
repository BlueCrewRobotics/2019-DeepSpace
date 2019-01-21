


#include <ctre/Phoenix.h>


class BC_TalonSRX : public virtual frc::SpeedController {
    
   public: 
    BC_TalonSRX(int device);
    void Set(double speed);
    void PIDWrite(double output);
    double Get() const;
    void SetInverted(bool isInverted);
    bool GetInverted() const;
    void Disable();
    void StopMotor();
    

    TalonSRX* ptr_talonSRX = nullptr;  
   private:
    double m_iSpeed = 0; 

};