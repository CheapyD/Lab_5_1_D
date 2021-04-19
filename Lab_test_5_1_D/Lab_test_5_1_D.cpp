#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_1_D/Triad.cpp"
#include "../Lab_5_1_D/FuzzyNumber.cpp"
#include "../Lab_5_1_D/MyException.cpp"
#include "../Lab_5_1_D/MyDerivedException.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Labtest51D
{
	TEST_CLASS(Labtest51D)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			FuzzyNumber V(4, 1, 7), L(6, 3, 9);
			FuzzyNumber C = V + L;
			Assert::AreEqual(C.GetX(), 10.0);
		}

		TEST_METHOD(TestMethod2)
		{
			Triad K(3.5, -9.4, 5.6), F(3.6, -9.3, 5.7);
			Assert::AreEqual(K > F, false);
		}
	};
}
