#pragma once

#include "BlfObjectFactory.h"
#include "CubeMeshFactory.h"

class CubeFactory : public BlfObjectFactory {
public:  //todo refactor
  std::string imagePath = "Brick1.png";

private:
  BlfObject* fill(BlfObject* cube) const {
    auto cubeMeshFactory = new CubeMeshFactory();
    auto mesh = cubeMeshFactory->newInstance(imagePath);

    cube
      ->addComponent<Transform>()
      ->addComponent<MeshHolder>();

    cube->getComponent<MeshHolder>()->drawMode = GL_TRIANGLES;
    cube->getComponent<MeshHolder>()->mesh = mesh;
    cube->getComponent<MeshHolder>()->shader = new Shader("sampleVert.vert", "sampleFrag.frag");

    return cube;
  }
};