#pragma once

#include "BlfObjectFactory.h"
#include "Transform.h"
#include "Camera.h"
#include "InputController.h"

class FppActorFactory : public BlfObjectFactory {
public:
  BlfObject* newInstance() const {
    auto fppActor = new BlfObject();

    fppActor->addComponent<Transform>();
    fppActor->addComponent<Camera>();
    fppActor->addComponent<InputController>();

    return fppActor;
  }
};