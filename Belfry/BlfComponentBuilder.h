#pragma once

#include <memory>
#include "BlfComponent.h"

template <typename T> class BlfComponentBuilder {
public:
  const T* build() {
    return _instance;
  };
  
  const T* start() {
    _instance = new T();
    return _instance;
  }

protected:
  T* _instance;
};