#pragma once

#include "BlfWorld.h"
#include "BlfObjectFactoryManager.h"

class BlfWorldFactory {
public:
  virtual const BlfWorld& newInstance() const = 0;
};