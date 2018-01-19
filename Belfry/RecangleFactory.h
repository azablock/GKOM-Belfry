#pragma once

#include "BlfObjectFactory.h"
#include "Transform.h"
#include "MeshHolder.h"
#include "RectangleMeshFactory.h"

class RecangleFactory : public BlfObjectFactory {
public:
  BlfObject* fill(BlfObject* rectangle) const {
    auto rectangleMeshFactory = new RectangleMeshFactory();
    auto mesh = rectangleMeshFactory->newInstance("GrayStoneRoad1.jpg");

    rectangle
      ->addComponent<Transform>()
      ->addComponent<MeshHolder>();

    rectangle->getComponent<MeshHolder>()->drawMode = GL_TRIANGLES;
    rectangle->getComponent<MeshHolder>()->mesh = mesh;
    rectangle->getComponent<MeshHolder>()->shader = new Shader("sampleVert.vert", "sampleFrag.frag");

    return rectangle;
  };
};