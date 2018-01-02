#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <list>
#include <map>
#include "BlfObject.h"
#include "BlfObjectFactory.h"

class BlfWorld {
public:

  ~BlfWorld() {
    _objects.clear();
  }

  static BlfWorld* instance();

  const void add(BlfObject* object) {
    string tag = object->tag();

    _objects.push_back(object);

    if (!tag.empty()) {
      _objectsByTags[tag] = object;
    }
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

  static BlfWorld* _instance;
  list<BlfObject*> _objects;
  map<std::string, BlfObject*> _objectsByTags;
  bool _isAlive;
};

//
//class Singleton
//{
//private:
//  /* Here will be the instance stored. */
//  static Singleton* instance;
//
//  /* Private constructor to prevent instancing. */
//  Singleton();
//
//public:
//  /* Static access method. */
//  static Singleton* getInstance();
//};
//
///* Null, because instance will be initialized on demand. */
//Singleton* Singleton::instance = 0;
//
//Singleton* Singleton::getInstance()
//{
//  if (instance == 0)
//  {
//    instance = new Singleton();
//  }
//
//  return instance;
//}
//
//Singleton::Singleton()
//{}