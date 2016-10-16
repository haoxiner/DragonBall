#pragma once
#define LOG
#ifdef LOG
#include <fstream>
#include <sstream>
#endif // LOG
namespace DragonBall
{
void Log(const char *msg);
}