#pragma once

#include "BlfObjectFactoryManager.h"
#include "CylinderFactory.h"
#include "RopePulleyAnimation.h"

class RopePulleyFactory : public BlfObjectFactory {
public:
  BlfObject* fill(BlfObject* ropePulley) const {
    BlfObjectFactoryManager::instance().get<CylinderFactory>()->fill(ropePulley);

    //ropePulley->addComponent<Animator>();

    //setupAnimation(ropePulley->getComponent<Animator>());

    return ropePulley;
  }

  void setupAnimation(Animator* animator) const {
    Animation* animation = new RopePulleyAnimation(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 0.05f);
    animator->addToChain(animation);
  }
};