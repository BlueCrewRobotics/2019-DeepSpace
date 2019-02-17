/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#pragma once
#include <frc/WPILib.h>

class BC_Trigger : public virtual frc::Trigger {

	public: 
		BC_Trigger();

		// Overides for the Trigger class
		bool Get();
        void Set(bool trigger);
	private:
		bool m_bTrigger = false;

};