#include "gtest/gtest.h"
#include "Transform.h"

TEST(Transform, TransformTest) {
  BlfComponent* transform = new Transform();
  EXPECT_NO_THROW();
}

//testy dla rotate, translate, scale