/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "common/BC_Logging.h"

BC_Logging::BC_Logging() {

}
BC_Logging::~BC_Logging() {
    BC_Logging::BC_Close();
    delete m_File;
    
}

bool BC_Logging::BC_Open(char* filename) {
    m_File->open(filename);
    return m_File->good();

}

void BC_Logging::BC_Close() {
    m_File->close();
}