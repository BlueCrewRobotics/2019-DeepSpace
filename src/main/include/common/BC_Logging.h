/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "frc/WPILib.h"
#include <iostream>
#include <fstream>

class BC_Logging {

public:
  BC_Logging();
  ~BC_Logging();
  bool BC_Open(char* filename);
  void BC_Close();

private:
  std::ofstream* m_File = new std::ofstream();

};