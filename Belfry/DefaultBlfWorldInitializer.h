#pragma once

#include "BlfWorldInitializer.h"
#include "BlfObjectFactoryManager.h"

class DefaultBlfWorldInitializer : public BlfWorldInitializer {

public:
  void init(BlfWorld& world) {
    BlfObjectFactoryManager& blfObjectFactoryManager = BlfObjectFactoryManager::instance();

    world.add(blfObjectFactoryManager.newInstanceFrom<FppActorFactory>());
    world.add(blfObjectFactoryManager.newInstanceFrom<RecangleFactory>());
  }

  void setup() {
    setupFppActor();
  }

private:
  void setupFppActor() {
    auto fppActor = BlfWorld::instance().getBlfObjectByTag("FppActor");
    
    auto transform = fppActor->getComponent<Transform>();
    transform->position += glm::vec3(0.0f, 0.0f, 7.0f);
   
    auto camera = fppActor->getComponent<Camera>();
    camera->changeLookDirection(glm::vec3(0.0f, 0.0f, 0.0f));
  }
};