
#define GLEW_STATIC
#include <GL/glew.h>
#include "gtest/gtest.h"
#include "BlfObjectFactoryManager.h"

// COS SIE WALI Z LINKOWANIEM OPEN_GL'A

class BlfObjectFactoryManagerTest : public ::testing::Test {
protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  BlfObjectFactoryManagerTest() {
    // You can do set-up work for each test here.
    //factoryManager = BlfObjectFactoryManager::instance();
  }

  virtual ~BlfObjectFactoryManagerTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
  //BlfObjectFactoryManager& factoryManager;
};

TEST_F(BlfObjectFactoryManagerTest, initTest) {
  //given
  auto fppActor = BlfObjectFactoryManager::instance().get<FppActorFactory>()->newInstance();
  
  //when

  //then
  EXPECT_TRUE(fppActor != nullptr);
}