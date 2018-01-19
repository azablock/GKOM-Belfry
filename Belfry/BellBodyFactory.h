#pragma once

#include "BlfObjectFactory.h"
#include "CylinderFactory.h"

class BellBodyFactory : public BlfObjectFactory {
public:
  BlfObject* fill(BlfObject* bellBody) const {
    BlfObjectFactoryManager::instance().get<CylinderFactory>()->fill(bellBody);

    bellBody->addComponent<Animator>();

    setupAnimation(bellBody->getComponent<Animator>());

    return bellBody;
  }

  void setupAnimation(Animator* animator) const {
    Animation* animation = new PendulumAnimation(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 2.0f, 0.0f), 0.2f);
    animator->addToChain(animation);
  }
};