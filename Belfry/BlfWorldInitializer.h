#pragma once

#include "BlfWorld.h"
#include "BlfObjectFactoryManager.h"

class BlfWorldInitializer {

public:
  virtual void init(BlfWorld& world) = 0;
};