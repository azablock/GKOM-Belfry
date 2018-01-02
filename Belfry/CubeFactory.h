#pragma once

#include "BlfObjectFactory.h"
#include "Transform.h"
#include "MeshHolder.h"
#include "CubeMeshFactory.h"

class CubeFactory : public BlfObjectFactory {
public:
  BlfObject* newInstance() const {
    auto cube = new BlfObject();

    //todo to be removed
    auto cubeMeshFactory = new CubeMeshFactory();
    //
    auto mesh = cubeMeshFactory->newInstance();

    cube
      ->addComponent<Transform>()
      ->addComponent<MeshHolder>();

    cube->getComponent<MeshHolder>()->mesh = mesh;
    cube->getComponent<MeshHolder>()->shader = new Shader("sampleVert.vert", "sampleFrag.frag");

    return cube;
  };
};