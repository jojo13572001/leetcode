#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../../../Project1/Solution.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			std::string paren = "(()";
			Solution solu;
			int result = solu.longestValidParentheses(paren);
			string test = std::to_string(result);
			Logger::WriteMessage(test.c_str());
			Assert::AreEqual(result, 2);
			// TODO: 您的測試程式碼在這裡
		}
		TEST_METHOD(TestMethod2)
		{
			std::string paren = ")()())";
			Solution solu;
			Assert::AreEqual(solu.longestValidParentheses(paren), 4);
			// TODO: 您的測試程式碼在這裡
		}
		TEST_METHOD(TestMethod3)
		{
			std::string paren = "()(()";
			Solution solu;
			Assert::AreEqual(solu.longestValidParentheses(paren), 4);
			// TODO: 您的測試程式碼在這裡
		}
	};
}