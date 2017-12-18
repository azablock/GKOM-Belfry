#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Belfry/BlfComponent.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BelfryTest {		
	
  TEST_CLASS(UnitTest1) {
	public:
		
		TEST_METHOD(TestMethod1) {
			// TODO: Your test code here
      BlfComponent component;

      Assert::AreEqual(1, component.value());
		}

	};
}