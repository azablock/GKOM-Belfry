#pragma once

#include "BlfObjectFactory.h"
#include "CubeMeshFactory.h"

class BellTongueFactory : public BlfObjectFactory {
public://todo move to TexutreLoader public static
  std::string imagePath;

private:
  BlfObject* fill(BlfObject* bellTongue) const {
    auto cubeMeshFactory = new CubeMeshFactory();
    auto mesh = cubeMeshFactory->newInstance(imagePath);

    bellTongue
      ->addComponent<Transform>()
      ->addComponent<MeshHolder>()
      ->addComponent<Animator>();

    bellTongue->getComponent<MeshHolder>()->drawMode = GL_TRIANGLES;
    bellTongue->getComponent<MeshHolder>()->mesh = mesh;
    bellTongue->getComponent<MeshHolder>()->shader = new Shader("sampleVert.vert", "sampleFrag.frag");

    setupAnimation(bellTongue->getComponent<Animator>());

    return bellTongue;
  }

  void setupAnimation(Animator* animator) const {
    Animation* animation = new RotationAnimation(2.0f, glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    animator->addToChain(animation);
  }
};