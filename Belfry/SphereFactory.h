#pragma once

#include "BlfObjectFactory.h"
#include "SphereMeshFactory.h"
#include "Animator.h"
#include "RotationAnimation.h"

class SphereFactory : public BlfObjectFactory {

  BlfObject* fill(BlfObject* sphere) const {
    auto sphereMeshFactory = new SphereMeshFactory();
    auto mesh = sphereMeshFactory->newInstance();

    sphere->addComponent<Transform>();

    sphere
      ->addComponent<Transform>()
      ->addComponent<MeshHolder>()
      ->addComponent<Animator>();

    sphere->getComponent<MeshHolder>()->drawMode = GL_TRIANGLES;
    sphere->getComponent<MeshHolder>()->mesh = mesh;
    sphere->getComponent<MeshHolder>()->shader = new Shader("sampleVert.vert", "sampleFrag.frag");

    auto animator = sphere->getComponent<Animator>();
    
    Animation* rotationAnimationX = new RotationAnimation(3.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    Animation* rotationAnimationY = new RotationAnimation(3.0f, glm::vec3(0.0f, 1.0f, 0.0f));

    animator->addToChain(rotationAnimationX);
    animator->addToChain(rotationAnimationY);

    return sphere;
  }
};