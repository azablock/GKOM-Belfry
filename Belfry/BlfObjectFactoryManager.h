#pragma once

#include <map>
#include <typeindex>
#include "Singleton.h"
#include "BlfObjectFactory.h"

class BlfObjectFactoryManager : public Singleton<BlfObjectFactoryManager> {
public:
  friend class Singleton<BlfObjectFactoryManager>;

  BlfObjectFactoryManager() {
    _factories = {};
  }

  template <typename T> void add() {
    _factories[typeid(T)] = new T();
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


};