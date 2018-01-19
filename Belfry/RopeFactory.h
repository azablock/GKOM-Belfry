#pragma once

#include "BlfObjectFactoryManager.h"
#include "CubeFactory.h"
#include "RopeAnimation.h"

class RopeFactory : public BlfObjectFactory {
public:
  BlfObject* fill(BlfObject* rope) const {
    BlfObjectFactoryManager::instance().get<CubeFactory>()->fill(rope);

    rope->addComponent<Animator>();

    setupAnimation(rope->getComponent<Animator>());

    return rope;
  }

  void setupAnimation(Animator* animator) const {
    Animation* animation = new RopeAnimation(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);
    animator->addToChain(animation);
  }
};