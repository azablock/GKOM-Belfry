#pragma once

#include "BlfObjectFactory.h"
#include "CubeMeshFactory.h"

class CubeFactory : public BlfObjectFactory {

  BlfObject* fill(BlfObject* cube) const {
    auto cubeMeshFactory = new CubeMeshFactory();
    auto mesh = cubeMeshFactory->newInstance();

    cube
      ->addComponent<Transform>()
      ->addComponent<MeshHolder>();

    cube->getComponent<MeshHolder>()->mesh = mesh;
    cube->getComponent<MeshHolder>()->shader = new Shader("sampleVert.vert", "sampleFrag.frag");

    return cube;
  }
};