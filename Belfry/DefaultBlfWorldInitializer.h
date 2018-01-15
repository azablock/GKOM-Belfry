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
    
    supportPillarNorth = world.addFrom(cubeFactory);
    supportPillarEast = world.addFrom(cubeFactory);
    supportPillarSouth = world.addFrom(cubeFactory);
    supportPillarWest = world.addFrom(cubeFactory);

    bellSupportLowerBeam = world.addFrom(cubeFactory);
    bellSupportHigherBeam = world.addFrom(cubeFactory);
  }

  void setup() {
    setupFppActor();
    setupSupportPillars();
    setupBellSupportBeams();
  }

private:
  void setupFppActor() {
    auto fppActor = BlfWorld::instance().getBlfObjectByTag("FppActor");
    
    auto transform = fppActor->getComponent<Transform>();
    transform->position += glm::vec3(0.0f, 0.0f, 7.0f);
  }

  void setupSupportPillars() {
    supportPillarNorth->getComponent<Transform>()->position = glm::vec3(4.0f, 0.0f, 0.0f);
    supportPillarNorth->getComponent<Transform>()->scale = glm::vec3(0.25f, 4.0f, 0.25f);

    supportPillarEast->getComponent<Transform>()->position = glm::vec3(0.0f, 0.0f, 4.0f);
    supportPillarEast->getComponent<Transform>()->scale = glm::vec3(0.25f, 4.0f, 0.25f);

    supportPillarSouth->getComponent<Transform>()->position = glm::vec3(-4.0f, 0.0f, 0.0f);
    supportPillarSouth->getComponent<Transform>()->scale = glm::vec3(0.25f, 4.0f, 0.25f);

    supportPillarWest->getComponent<Transform>()->position = glm::vec3(0.0f, 0.0f, -4.0f);
    supportPillarWest->getComponent<Transform>()->scale = glm::vec3(0.25f, 4.0f, 0.25f);
  }

  void setupBellSupportBeams() {
    bellSupportLowerBeam->getComponent<Transform>()->position = glm::vec3(0.0f, 8.5f, 0.0f);
    bellSupportLowerBeam->getComponent<Transform>()->scale = glm::vec3(0.25f, 0.25f, 3.0f);


  }

  BlfObject* supportPillarNorth;
  BlfObject* supportPillarEast;
  BlfObject* supportPillarSouth;
  BlfObject* supportPillarWest;

  BlfObject* bellSupportLowerBeam;
  BlfObject* bellSupportHigherBeam;
};