#pragma once

#include "BlfWorld.h"
#include "BlfObjectFactoryManager.h"

class BlfWorldInitializer {

public:
  virtual void init(BlfWorld* world) = 0;

  BlfWorldInitializer() {
    blfObjectFactoryManager = new BlfObjectFactoryManager(); //todo dependency to be removed - singleton
  }

protected:
  BlfObjectFactoryManager* blfObjectFactoryManager; //todo dependency to be removed - singleton
};