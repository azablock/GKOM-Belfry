#pragma once

#include "BlfWorldInitializer.h"
#include "BlfObjectFactoryManager.h"

class DefaultBlfWorldInitializer : public BlfWorldInitializer {

public:
  void init(BlfWorld* world) {
    world->add(blfObjectFactoryManager->newInstanceFrom<FppActorFactory>());
    world->add(blfObjectFactoryManager->newInstanceFrom<WindowContainerFactory>());
  }
};