#include "gtest/gtest.h"
#include "BlfObject.h"
#include "Transform.h"

TEST(BlfObject, constructorTest) {
  //given
  auto object = new BlfObject();
  map<type_index, BlfComponent*> emptyMap = {};

  //when

  //then
  EXPECT_EQ(emptyMap, object->components());
}

TEST(BlfObject, getComponentTest) {
  //given
  auto object = new BlfObject();
  auto transform = new Transform(); 
  // fixme?? jak tutaj dam BlfComponent* to nie znajduje w typeid(T) w getComponent

  //when
  object->addComponent(transform);
  auto transformFromObject = object->getComponent<Transform>();

  //then
  EXPECT_EQ(transform, transformFromObject);
  EXPECT_EQ(object, transformFromObject->parent());
}