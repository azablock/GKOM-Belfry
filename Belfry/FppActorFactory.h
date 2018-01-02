#pragma once

#include "BlfObjectFactory.h"
#include "Transform.h"
#include "Camera.h"
#include "InputController.h"
#include "Movement.h"

class FppActorFactory : public BlfObjectFactory {
public:
  BlfObject* newInstance() const {
    auto fppActor = new BlfObject();

    fppActor->addComponent<Transform>()
            ->addComponent<Camera>()
            ->addComponent<InputController>()
            ->addComponent<Movement>();

    return fppActor;
  }
};