#include "System.h"
ComponentManager *System::componentManager_ = nullptr;
void System::SetComponentManager(ComponentManager * componentManager)
{
  componentManager_ = componentManager;
}
