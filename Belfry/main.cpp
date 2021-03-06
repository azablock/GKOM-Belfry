#include "gtest/gtest.h"
#include"DefaultBlfWorldInitializer.h"
#include <SOIL.h>

#define TEST_MODE_ENABLED false;

#if TEST_MODE_ENABLED
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#endif

#if !TEST_MODE_ENABLED
int main() {
  auto world = BlfWorld::instance();
  auto worldInitializer = new DefaultBlfWorldInitializer();
  worldInitializer->init(world);

  world->awake();

  while (world->isAlive()) {
    world->update();
    world->lateUpdate();
  }

  return 0;
}
#endif