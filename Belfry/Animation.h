#pragma once

#include "BlfObject.h"

class Animation {
public:
  Animation() {}

  Animation(float length) {
    this->length = length;
    this->isPlaying = false;
  }

  virtual void animate(BlfObject* target) = 0;

  float length;
  bool isPlaying;
};