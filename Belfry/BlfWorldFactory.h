#pragma once

#include "BlfWorld.h"
#include "BlfObjectFactoryManager.h"

class BlfWorldFactory {
public:
  BlfWorldFactory() {
    blfObjectFactoryManager = new BlfObjectFactoryManager(); //todo dependency to be removed - singleton
  }

  virtual const BlfWorld& newInstance() const = 0;

protected:
  BlfObjectFactoryManager* blfObjectFactoryManager; //todo dependency to be removed - singleton
};