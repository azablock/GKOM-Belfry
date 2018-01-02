#pragma once

class BlfObject;

class BlfComponent {
public:
  virtual const void awake() {};
  virtual const void update() {};
  virtual const void lateUpdate() {};
  virtual const void destroy() {};

  void setParent(BlfObject* parent) {
    _parent = parent;
  }

  BlfObject* parent() const {
    return _parent;
  }

protected:
  BlfObject* _parent;
};