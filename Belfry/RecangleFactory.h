#pragma once

#include "BlfObjectFactory.h"
#include "Transform.h"
#include "MeshHolder.h"
#include "RectangleMeshFactory.h"

class RecangleFactory : public BlfObjectFactory {
private:
  BlfObject* fill(BlfObject* rectangle) const {
    auto rectangleMeshFactory = new RectangleMeshFactory();
    auto mesh = rectangleMeshFactory->newInstance("Brick1.png");

    rectangle
      ->addComponent<Transform>()
      ->addComponent<MeshHolder>();

    rectangle->getComponent<MeshHolder>()->drawMode = GL_TRIANGLES;
    rectangle->getComponent<MeshHolder>()->mesh = mesh;
    rectangle->getComponent<MeshHolder>()->shader = new Shader("sampleVert.vert", "sampleFrag.frag");

    return rectangle;
  };
};