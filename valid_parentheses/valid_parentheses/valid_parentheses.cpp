// valid_parentheses.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"

int main()
{
	std::string operation = "(])";
	Solution solu;
	std::cout<<solu.isValid(operation)<<std::endl;
	getchar();
	return 0;
}

