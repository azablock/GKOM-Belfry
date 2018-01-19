#pragma once

#include "BlfWorldInitializer.h"
#include "BlfObjectFactoryManager.h"
#include "FppActorFactory.h"
#include "RecangleFactory.h"
#include "CubeFactory.h"
#include "SphereFactory.h"
#include "CylinderFactory.h"
#include "BellBodyFactory.h"
#include "BellTongueFactory.h"
#include "BellHeadFactory.h"
#include "RopePulleyFactory.h"
#include "RopeFactory.h"

class DefaultBlfWorldInitializer : public BlfWorldInitializer {

public:
  void init(BlfWorld& world) {
    BlfObjectFactoryManager& objManager = BlfObjectFactoryManager::instance();
    objManager.add<FppActorFactory>();
    objManager.add<RecangleFactory>();
    objManager.add<CubeFactory>();
    objManager.add<SphereFactory>();
    objManager.add<CylinderFactory>();
    objManager.add<BellBodyFactory>();
    objManager.add<BellTongueFactory>();
    objManager.add<BellHeadFactory>();
    objManager.add<RopePulleyFactory>();
    objManager.add<RopeFactory>();

    //todo refactor - Manager singleton
    cubeFactory = objManager.get<CubeFactory>();
    rectangleFactory = objManager.get<RecangleFactory>();
    sphereFactory = objManager.get<SphereFactory>();
    cylinderFactory = objManager.get<CylinderFactory>();
    bellBodyFactory = objManager.get<BellBodyFactory>();
    bellTongueFactory = objManager.get<BellTongueFactory>();
    bellHeadFactory = objManager.get<BellHeadFactory>();
    //ropePulleyFactory = objManager.get<RopePulleyFactory>();
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

    cubeFactory->imagePath = "GrayStoneRoad1.jpg";
    ground = world.addFrom(cubeFactory);

    cylinderFactory->imagePath = "Brass1.jpg";
    bellBody = world.addFrom(bellBodyFactory);

    cubeFactory->imagePath = "DarkMetal1.png";
    bellTongue = world.addFrom(bellTongueFactory);

    sphereFactory->imagePath = "Brass1.jpg";
    bellHead = world.addFrom(bellHeadFactory);


    //cylinder
    cylinderFactory->imagePath = "DarkMetal1.png";
    ropePulley = world.addFrom(objManager.get<RopePulleyFactory>());
    
    //cube
    cubeFactory->imagePath = "Brick1.png";
    rope = world.addFrom(objManager.get<RopeFactory>());

    //cube
    cubeFactory->imagePath = "DarkMetal1.png";
    ropePulleySupportBeam = world.addFrom(cubeFactory);
  }

  void setup() {
    setupFppActor();
    
    setupSupportPillars();
    setupBellSupportBeams();
    
    setupGround();
    
    setupBellBody();
    setupBellTongue();
    setupBellHead();

    setupRopePulley();
    setupRope();
    setupRopePulleySupportBeam();
  }

private:
  void setupFppActor() {
    auto fppActor = BlfWorld::instance().getBlfObjectByTag("FppActor");
    
    auto transform = fppActor->getComponent<Transform>();
    transform->position = glm::vec3(0.0f, 0.0f, 15.0f);
  }

  void setupSupportPillars() {
    GLfloat positionY = 2.25f;
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
    bellSupportHigherBeam->getComponent<Transform>()->position = glm::vec3(0.0f, 7.0f, 0.0f);
    bellSupportHigherBeam->getComponent<Transform>()->scale = glm::vec3(0.5f, 0.25f, 2.5f);

    bellSupportLowerBeam->getComponent<Transform>()->position = glm::vec3(0.0f, 6.5f, 0.0f);
    bellSupportLowerBeam->getComponent<Transform>()->scale = glm::vec3(0.25f, 0.25f, 2.5f);
    bellSupportLowerBeam->getComponent<Transform>()->rotation = glm::vec3(0.0f, 1.0f, 0.0f);
    bellSupportLowerBeam->getComponent<Transform>()->rotationAngle = glm::radians(90.0f);
  }

  void setupGround() {
    GLfloat groundSize = 10.0f;

    ground->getComponent<Transform>()->position = glm::vec3(0.0f, -2.0f, 0.0f);
    ground->getComponent<Transform>()->scale = glm::vec3(groundSize, 0.01f, groundSize);
  }

  void setupBellBody() {
    bellBody->getComponent<Transform>()->position = glm::vec3(0.0f, 3.75f, 0.0f);
    bellBody->getComponent<Transform>()->scale = glm::vec3(0.75f);
  }

  void setupBellTongue() {
    bellTongue->getComponent<Transform>()->position = glm::vec3(0.0f, 4.25f, 0.0f);
    bellTongue->getComponent<Transform>()->scale = glm::vec3(0.075f, 1.25f, 0.075f);
  }

  void setupBellHead() {
    bellHead->getComponent<Transform>()->position = glm::vec3(0.0f, 5.25f, 0.0f);
    bellHead->getComponent<Transform>()->scale = glm::vec3(0.75f);
  }

  void setupRopePulley() {
    ropePulley->getComponent<Transform>()->position = glm::vec3(0.0f, 6.0f, 1.35f);
    ropePulley->getComponent<Transform>()->rotation = glm::vec3(1.0f, 0.0f, 0.0f);
    ropePulley->getComponent<Transform>()->rotationAngle = glm::radians(90.0f);
    ropePulley->getComponent<Transform>()->scale = glm::vec3(0.2f);
  }

  void setupRope() {
    rope->getComponent<Transform>()->position = glm::vec3(0.25f, 4.0f, 1.5f);
    rope->getComponent<Transform>()->scale = glm::vec3(0.025f, 0.5f, 0.025f);
    rope->getComponent<Transform>()->rotation = glm::vec3(0.0f, 1.0f, 0.0f);
    rope->getComponent<Transform>()->rotationAngle = glm::radians(180.0f);
  }

  void setupRopePulleySupportBeam() {
    ropePulleySupportBeam->getComponent<Transform>()->position = glm::vec3(0.0f, 6.0f, 0.0f);
    ropePulleySupportBeam->getComponent<Transform>()->scale = glm::vec3(0.05f, 0.05f, 2.0f);
  }

  BlfObject* supportPillarNorth;
  BlfObject* supportPillarEast;
  BlfObject* supportPillarSouth;
  BlfObject* supportPillarWest;

  BlfObject* bellBody;
  BlfObject* bellTongue;
  BlfObject* bellHead;
  BlfObject* bellSupportLowerBeam;
  BlfObject* bellSupportHigherBeam;

  BlfObject* ground;
  
  BlfObject* ropePulley;
  BlfObject* rope;
  BlfObject* ropePulleySupportBeam;

  CubeFactory* cubeFactory;
  RecangleFactory* rectangleFactory;
  SphereFactory* sphereFactory;
  CylinderFactory* cylinderFactory;
  BellBodyFactory* bellBodyFactory;
  BellTongueFactory* bellTongueFactory;
  BellHeadFactory* bellHeadFactory;
};