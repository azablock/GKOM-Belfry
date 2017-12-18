#pragma once

#include "BlfObjectFactory.h"
#include "GLWindowContainer.h"

class WindowContainerFactory : public BlfObjectFactory {

public:
  BlfObject* newInstance() const {
    auto windowContainer = new BlfObject("WindowContainer");
    windowContainer->addComponent<GLWindowContainer>();
    
    return windowContainer;
  }
};