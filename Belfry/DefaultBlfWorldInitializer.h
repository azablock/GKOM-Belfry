#pragma once

#include "BlfWorldInitializer.h"
#include "BlfObjectFactoryManager.h"

class DefaultBlfWorldInitializer : public BlfWorldInitializer {

public:
  void init(BlfWorld& world) {
    BlfObjectFactoryManager& objManager = BlfObjectFactoryManager::instance();

    //todo refactor - Manager singleton
    cubeFactory = objManager.get<CubeFactory>();
    rectangleFactory = objManager.get<RecangleFactory>();
    sphereFactory = objManager.get<SphereFactory>();
    bellBodyFactory = objManager.get<BellBodyFactory>();
    bellTongueFactory = objManager.get<BellTongueFactory>();
    // ------------------------

    world.add(objManager.newInstanceFrom<FppActorFactory>("FppActor"));
    
    cubeFactory->imagePath = "Stone1.png";
    supportPillarNorth = world.addFrom(cubeFactory);
    supportPillarEast = world.addFrom(cubeFactory);
    supportPillarSouth = world.addFrom(cubeFactory);
    supportPillarWest = world.addFrom(cubeFactory);

    cubeFactory->imagePath = "Wood1.jpg";
    bellSupportLowerBeam = world.addFrom(cubeFactory);
    bellSupportHigherBeam = world.addFrom(cubeFactory);

    cubeFactory->imagePath = "gridBlackWhite.jpg";
    ground = world.addFrom(cubeFactory);


    bellBodyFactory->imagePath = "Brick1.png";
    bellBody = world.addFrom(bellBodyFactory);

    bellTongueFactory->imagePath = "Brick1.png";
    bellTongue = world.addFrom(bellTongueFactory);

    sphere = world.addFrom(sphereFactory);
  }

  void setup() {
    setupFppActor();
    setupSupportPillars();
    setupBellSupportBeams();
    setupGround();
    setupBellBody();
    setupBellTongue();

    //todo to be removed
    sphere->getComponent<Transform>()->position = glm::vec3(10.0f, 0.0f, 0.0f);
    //-----------------------------
  }

private:
  void setupFppActor() {
    auto fppActor = BlfWorld::instance().getBlfObjectByTag("FppActor");
    
    auto transform = fppActor->getComponent<Transform>();
    transform->position = glm::vec3(0.0f, 0.0f, 15.0f);
  }

  void setupSupportPillars() {
    GLfloat positionY = 2.0f;
    GLfloat horizontalPositionOffset = 2.0f;
    GLfloat pillarHeight = 4.0f;
    GLfloat higherPillarOffsetY = 0.5f;

    supportPillarNorth->getComponent<Transform>()->position = glm::vec3(horizontalPositionOffset, positionY, 0.0f);
    supportPillarNorth->getComponent<Transform>()->scale = glm::vec3(0.25f, pillarHeight, 0.25f);

    supportPillarEast->getComponent<Transform>()->position = glm::vec3(0.0f, positionY, horizontalPositionOffset);
    supportPillarEast->getComponent<Transform>()->scale = glm::vec3(0.25f, pillarHeight + higherPillarOffsetY, 0.25f);

    supportPillarSouth->getComponent<Transform>()->position = glm::vec3(-horizontalPositionOffset, positionY, 0.0f);
    supportPillarSouth->getComponent<Transform>()->scale = glm::vec3(0.25f, pillarHeight, 0.25f);

    supportPillarWest->getComponent<Transform>()->position = glm::vec3(0.0f, positionY, -horizontalPositionOffset);
    supportPillarWest->getComponent<Transform>()->scale = glm::vec3(0.25f, pillarHeight + higherPillarOffsetY, 0.25f);
  }

  void setupBellSupportBeams() {
    bellSupportHigherBeam->getComponent<Transform>()->position = glm::vec3(0.0f, 6.75f, 0.0f);
    bellSupportHigherBeam->getComponent<Transform>()->scale = glm::vec3(0.5f, 0.25f, 2.5f);

    bellSupportLowerBeam->getComponent<Transform>()->position = glm::vec3(0.0f, 6.25f, 0.0f);
    bellSupportLowerBeam->getComponent<Transform>()->scale = glm::vec3(0.25f, 0.25f, 2.5f);
    bellSupportLowerBeam->getComponent<Transform>()->rotation = glm::vec3(0.0f, 1.0f, 0.0f);
    bellSupportLowerBeam->getComponent<Transform>()->rotationAngle = glm::radians(90.0f);
  }

  void setupGround() {
    GLfloat groundSize = 40.0f;

    ground->getComponent<Transform>()->position = glm::vec3(0.0f, -2.0f, 0.0f);
    ground->getComponent<Transform>()->scale = glm::vec3(groundSize, 0.01f, groundSize);
  }

  void setupBellBody() {
    bellBody->getComponent<Transform>()->position = glm::vec3(0.0f, 4.0f, -1.0f);
    bellBody->getComponent<Transform>()->scale = glm::vec3(0.5f);
  }

  void setupBellTongue() {
    bellTongue->getComponent<Transform>()->position = glm::vec3(0.0f, 2.0f, -1.0f);
    bellTongue->getComponent<Transform>()->scale = glm::vec3(0.25f);
  }

  BlfObject* supportPillarNorth;
  BlfObject* supportPillarEast;
  BlfObject* supportPillarSouth;
  BlfObject* supportPillarWest;

  BlfObject* bellBody;
  BlfObject* bellTongue;
  BlfObject* bellSupportLowerBeam;
  BlfObject* bellSupportHigherBeam;

  BlfObject* ground;
  
  //todo to be removed
  BlfObject* sphere;
  //------------------------------

  CubeFactory* cubeFactory;
  RecangleFactory* rectangleFactory;
  SphereFactory* sphereFactory;
  BellBodyFactory* bellBodyFactory;
  BellTongueFactory* bellTongueFactory;
};