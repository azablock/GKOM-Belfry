#include <glm/glm.hpp>
#include "gtest/gtest.h"

TEST(vec3, vec3additionTest) {
  //given
  glm::vec3 vector = glm::vec3(0.0f, 0.0f, 0.0f);

  //when
  vector += glm::vec3(1.0f, 0.0f, 0.0f);

  //then
  EXPECT_EQ(vector.x, 1);
  EXPECT_EQ(vector.y, 0);
  EXPECT_EQ(vector.z, 0);
}