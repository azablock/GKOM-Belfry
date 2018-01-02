#pragma once

#include <map>
#include <typeindex>
#include "BlfComponent.h"

using namespace std;

class BlfObject {
public:
  BlfObject();

  BlfObject(string tag) {
    _components = {};
    _tag = tag;
  };

  ~BlfObject();

  template <typename T> BlfObject* addComponent(T* component) {
    dynamic_cast<BlfComponent*>(component)->setParent(this);
    _components[typeid(T)] = component;

    return this;
  }

  template <typename T> BlfObject* addComponent() {
    T* component = new T();
    return addComponent(component);
  }

  template <typename T> T* getComponent() const {
    auto iterator = _components.find(typeid(T));
    return iterator != std::end(_components) ? dynamic_cast<T*>(iterator->second) : nullptr;
  }

  const void awake() {
    for (auto const& entry : _components)
      entry.second->awake();
  }

  const void update() {
    for (auto const& entry : _components) {
      entry.second->update();
    }
  }

  const void lateUpdate() {
    for (auto const& entry : _components) {
      entry.second->lateUpdate();
    }
  }

  map<type_index, BlfComponent*> components() const;

  string tag() const {
    return _tag;
  }

private:
  map<type_index, BlfComponent*> _components;
  string _tag;
};