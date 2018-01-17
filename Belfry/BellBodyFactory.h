#pragma once

#include "BlfObjectFactory.h"
#include "CubeMeshFactory.h"

class BellBodyFactory : public BlfObjectFactory {
public:
  std::string imagePath;

private:
  BlfObject* fill(BlfObject* bellBody) const {
    auto cubeMeshFactory = new CubeMeshFactory();
    auto mesh = cubeMeshFactory->newInstance(imagePath);

    bellBody
      ->addComponent<Transform>()
      ->addComponent<MeshHolder>()
      ->addComponent<Animator>();

    bellBody->getComponent<MeshHolder>()->drawMode = GL_TRIANGLES;
    bellBody->getComponent<MeshHolder>()->mesh = mesh;
    bellBody->getComponent<MeshHolder>()->shader = new Shader("sampleVert.vert", "sampleFrag.frag");

    setupAnimation(bellBody->getComponent<Animator>());

    return bellBody;
  }

  void setupAnimation(Animator* animator) const {
    Animation* animation = new RotationAnimation(2.0f, glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    animator->addToChain(animation);
  }
};