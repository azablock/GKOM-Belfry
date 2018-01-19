#pragma once

#include "BlfObjectFactoryManager.h"
#include "CubeFactory.h"

class BellTongueFactory : public BlfObjectFactory {
public:
  BlfObject* fill(BlfObject* bellTongue) const {
    BlfObjectFactoryManager::instance().get<CubeFactory>()->fill(bellTongue);

    bellTongue->addComponent<Animator>();

    setupAnimation(bellTongue->getComponent<Animator>());

    return bellTongue;
  }

  void setupAnimation(Animator* animator) const {
    Animation* animation = new PendulumAnimation(glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 2.0f, 0.0f), 0.09f);
    animator->addToChain(animation);
  }
};