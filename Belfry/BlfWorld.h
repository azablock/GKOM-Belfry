#pragma once

#include <list>
#include <map>
#include <assert.h>
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

  BlfObject* add(BlfObject* object) {
    string tag = object->tag();

    _objects.push_back(object);

    if (!tag.empty()) {
      _objectsByTags[tag] = object;
    }

    return object;
  }

  BlfObject* addFrom(BlfObjectFactory* factory, std::string tag = "") {
    auto object = factory->newInstance(tag);
    _objects.push_back(object);

    return object;
  }

  void awake() const {
    for (auto const& object : _objects)
      object->awake();
  }

  void update() const {
    for (auto const& object : _objects)
      object->update();
  }

  void lateUpdate() const {
    for (auto const& object : _objects)
      object->lateUpdate();
  }

  void exit() {
    _isAlive = false;
  }

  bool isAlive() const {
    return _isAlive;
  }

  BlfObject* getBlfObjectByTag(string tag) const {
    auto iterator = _objectsByTags.find(tag);
    assert(iterator != std::end(_objectsByTags));
    return iterator->second;
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