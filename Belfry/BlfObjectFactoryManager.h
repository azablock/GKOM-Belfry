#pragma once

#include <map>
#include <typeindex>
#include "Singleton.h"
#include "BlfObjectFactory.h"
#include "FppActorFactory.h"
#include "RecangleFactory.h"

class BlfObjectFactoryManager : public Singleton<BlfObjectFactoryManager> {
public:
  friend class Singleton<BlfObjectFactoryManager>;

  BlfObjectFactoryManager() {
    _factories = {};

    add<FppActorFactory>();
    add<RecangleFactory>();
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