#include "Log.h"

void DragonBall::Log(const char * msg)
{
#ifdef LOG
  std::ofstream file("D:/log.log", std::ios::app);
  file << msg << std::endl;
  file.close();
#endif // LOG
}
