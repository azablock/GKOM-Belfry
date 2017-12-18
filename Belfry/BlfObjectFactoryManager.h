#pragma once

#include <map>
#include <typeindex>
#include "BlfObjectFactory.h"
#include "FppActorFactory.h"
#include "WindowContainerFactory.h"


//todo singleton
class BlfObjectFactoryManager {
public:
  BlfObjectFactoryManager() {
    _factories = {};

    add<FppActorFactory>();
    add<WindowContainerFactory>();
  }

  template <typename T> BlfObject* newInstanceFrom() {
    BlfObjectFactory* factory = get<T>();
    return factory->newInstance();
  }

private:
  map<type_index, BlfObjectFactory*> _factories;

  template <typename T> void add() {
    _factories[typeid(T)] = new T();
  }

  template <typename T> T* get() const {
    auto iterator = _factories.find(typeid(T));
    return iterator != std::end(_factories) ? dynamic_cast<T*>(iterator->second) : nullptr;
  }
};