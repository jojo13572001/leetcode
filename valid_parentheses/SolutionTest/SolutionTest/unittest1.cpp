#include "stdafx.h"
#include "CppUnitTest.h"
#include  "../../valid_parentheses/Solution.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolutionTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		
		TEST_METHOD(TestMethod1)
		{
			std::string parantheses = "";
			Solution soluTest;
			Assert::AreEqual(soluTest.isValid(parantheses), true);
		}
		TEST_METHOD(TestMethod2)
		{
			std::string parantheses = "()";
			Solution soluTest;
			Assert::AreEqual(soluTest.isValid(parantheses), true);
		}
		TEST_METHOD(TestMethod3)
		{
			std::string parantheses = "(])";
			Solution soluTest;
			Assert::AreEqual(soluTest.isValid(parantheses), false);
		}

	};
}