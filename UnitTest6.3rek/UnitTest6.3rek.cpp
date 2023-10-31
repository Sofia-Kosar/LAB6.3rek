#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB6.3pek/LAB6.3pek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63rek
{
	TEST_CLASS(UnitTest63rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 8, 2, 3, 56, 5, 6 };
			int n = 6;

			double z = findMinR(a, n);
			Assert::AreEqual(z, 2.0);
		}
	};
}
