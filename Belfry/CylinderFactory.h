#pragma once

#include "BlfObjectFactory.h"
#include "CylinderMeshFactory.h"
#include "PendulumAnimation.h"

class CylinderFactory : public BlfObjectFactory {
public:  //todo refactor
  std::string imagePath = "Brass1.jpg";

  BlfObject* fill(BlfObject* cylinder) const {
    auto cylinderMeshFactory = new CylinderMeshFactory();
    auto mesh = cylinderMeshFactory->newInstance(imagePath);

    cylinder
      ->addComponent<Transform>()
      ->addComponent<MeshHolder>();

    cylinder->getComponent<MeshHolder>()->drawMode = GL_TRIANGLES;
    cylinder->getComponent<MeshHolder>()->mesh = mesh;
    cylinder->getComponent<MeshHolder>()->shader = new Shader("sampleVert.vert", "sampleFrag.frag");

    return cylinder;
  }
};