#pragma once

#include <list>
#include <map>
#include "BlfObject.h"
#include "BlfObjectFactory.h"
#include <GLFW/glfw3.h>
#include "Singleton.h"

class BlfWorld : public Singleton<BlfWorld> {
public:

  friend class Singleton<BlfWorld>;

  ~BlfWorld() {
    _objects.clear();
  }

  const BlfObject* add(BlfObject* object) {
    string tag = object->tag();

    _objects.push_back(object);

    if (!tag.empty()) {
      _objectsByTags[tag] = object;
    }

    return object;
  }

  const void addFrom(BlfObjectFactory* factory) {
    _objects.push_back(factory->newInstance());
  }

  const void awake() const {
    for (auto const& object : _objects)
      object->awake();
  }

  const void update() const {
    for (auto const& object : _objects)
      object->update();
  }

  const void lateUpdate() const {
    for (auto const& object : _objects)
      object->lateUpdate();
  }

  const void exit() {
    _isAlive = false;
  }

  const bool isAlive() const {
    return _isAlive;
  }

  const BlfObject* getBlfObjectByTag(string tag) {
    auto iterator = _objectsByTags.find(tag);
    return iterator != std::end(_objectsByTags) ? iterator->second : nullptr;
  }

private:
  BlfWorld() {
    _objects = {};
    _isAlive = true;
  }

  list<BlfObject*> _objects;
  map<std::string, BlfObject*> _objectsByTags;
  bool _isAlive;
};