#pragma once

#include <map>
#include <typeindex>
#include "Singleton.h"
#include "BlfObjectFactory.h"
#include "FppActorFactory.h"
#include "RecangleFactory.h"
#include "CubeFactory.h"
#include "SphereFactory.h"

class BlfObjectFactoryManager : public Singleton<BlfObjectFactoryManager> {
public:
  friend class Singleton<BlfObjectFactoryManager>;

  BlfObjectFactoryManager() {
    _factories = {};

    add<FppActorFactory>();
    add<RecangleFactory>();
    add<CubeFactory>();
    add<SphereFactory>();
  }

  template <typename T> T* get() const {
    auto iterator = _factories.find(typeid(T));
    return iterator != std::end(_factories) ? dynamic_cast<T*>(iterator->second) : nullptr;
  }

  template <typename T> BlfObject* newInstanceFrom(string tag = "") {
    BlfObjectFactory* factory = get<T>();
    return factory->newInstance(tag);
  }

private:
  map<type_index, BlfObjectFactory*> _factories;

  template <typename T> void add() {
    _factories[typeid(T)] = new T();
  }

  
};