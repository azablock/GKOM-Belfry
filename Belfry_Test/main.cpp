#include "../BelfryModel/BfComponent.h"
#include "gtest/gtest.h"

TEST(exampleTest, myTest) {
  EXPECT_EQ(1, 1);
}

TEST(exampleTest, value) {
  BfComponent component;

  EXPECT_EQ(component.test(), 10);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}