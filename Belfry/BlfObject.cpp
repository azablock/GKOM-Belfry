#include "BlfObject.h"

BlfObject::BlfObject() {
  _components = {};
}

BlfObject::~BlfObject() {
  _components.clear();
}

map<type_index, BlfComponent*> BlfObject::components() const {
  return _components;
}

//https://stackoverflow.com/questions/44105058/how-does-unitys-getcomponent-work