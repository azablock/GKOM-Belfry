#pragma once

#include "BlfWorldInitializer.h"
#include "BlfObjectFactoryManager.h"

class DefaultBlfWorldInitializer : public BlfWorldInitializer {

public:
  void init(BlfWorld& world) {
    BlfObjectFactoryManager& objManager = BlfObjectFactoryManager::instance();

    world.add(objManager.newInstanceFrom<FppActorFactory>("FppActor"));
    world.add(objManager.newInstanceFrom<RecangleFactory>());
    
    auto cubeFactory = objManager.get<CubeFactory>();
    world.add(cubeFactory->newInstance("Cube"));
    
    //supportPillarNorth = world.addFrom(cubeFactory);
    //supportPillarEast = world.addFrom(cubeFactory);
    //supportPillarSouth = world.addFrom(cubeFactory);
    //supportPillarWest = world.addFrom(cubeFactory);
  }

  void setup() {
    setupFppActor();
    setupSupportPillars();
  }

private:
  void setupFppActor() {
    auto fppActor = BlfWorld::instance().getBlfObjectByTag("FppActor");
    
    auto transform = fppActor->getComponent<Transform>();
    transform->position += glm::vec3(0.0f, 0.0f, 7.0f);
  }

  void setupSupportPillars() {

    //glPushMatrix();
    //glLoadIdentity();

    //supportPillarNorth->getComponent<Transform>()->scale = glm::vec3(2.0f, 1.0f, 1.0f);
    //supportPillarNorth->getComponent<Transform>()->position = glm::vec3(4.0f, 0.0f, 0.0f);

    //glTranslatef(2.0f, 1.0f, 1.0f);
    //supportPillarNorth->getComponent<MeshHolder>()->update();

    //glPopMatrix();
  }

  BlfObject* supportPillarNorth;
  BlfObject* supportPillarEast;
  BlfObject* supportPillarSouth;
  BlfObject* supportPillarWest;
};