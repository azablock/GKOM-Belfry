#pragma once

#include "BlfObject.h"

class BlfObjectFactory {
public:
  virtual BlfObject* newInstance(std::string tag = "") const {
    auto object = tag.empty() ? new BlfObject() : new BlfObject(tag);
    return fill(object);
  };

protected:
  virtual BlfObject* fill(BlfObject* object) const = 0;
};