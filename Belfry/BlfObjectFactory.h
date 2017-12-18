#pragma once

#include "BlfObject.h"

class BlfObjectFactory {
public:
  virtual BlfObject* newInstance() const = 0;
};