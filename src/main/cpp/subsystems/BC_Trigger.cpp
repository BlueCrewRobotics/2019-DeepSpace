/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "BC_Trigger.h"


BC_Trigger::BC_Trigger(){

}

void BC_Trigger::Set(bool trigger){
    m_bTrigger = trigger;
}

bool BC_Trigger::Get() {
    return m_bTrigger;
}