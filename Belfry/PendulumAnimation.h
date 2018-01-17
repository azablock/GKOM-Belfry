#pragma once

#include "Animation.h"
#include "Transform.h"

class PendulumAnimation : public Animation {
public:
  virtual void animate(BlfObject* target) {
        
  }

private:
  GLfloat maxDeviation;
};