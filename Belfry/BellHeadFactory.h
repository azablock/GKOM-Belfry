#pragma once

#include "BlfObjectFactoryManager.h"
#include "SphereFactory.h"

class BellHeadFactory : public BlfObjectFactory {
public:
  BlfObject* fill(BlfObject* bellHead) const {
    BlfObjectFactoryManager::instance().get<SphereFactory>()->fill(bellHead);

    bellHead->addComponent<Animator>();

    setupAnimation(bellHead->getComponent<Animator>());

    return bellHead;
  }

  void setupAnimation(Animator* animator) const {
    Animation* animation = new PendulumAnimation(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 2.0f, 0.0f), 0.06f);
    animator->addToChain(animation);
  }
};