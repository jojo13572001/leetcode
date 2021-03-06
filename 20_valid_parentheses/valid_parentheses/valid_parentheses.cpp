// valid_parentheses.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include "Solution.h"

int main()
{
	Solution solution;
	solution.isValid("(])");
	return 0;
}

class Solution {
public:
	bool isValid(string s) {
		if (0 == s.length()) {
			return true;
		}

		stack<char> Stack;
		Stack.push(s[0]);
		std::map<char, char> parnethesis = { { '{', '}' },
											 { '[', ']' },
											 { '(', ')' } };
		for (int i = 1; i < s.length(); i++) {
			if (!Stack.empty() && parnethesis[Stack.top()] == s[i]) {
				Stack.pop();
			}
			else {
				Stack.push(s[i]);
			}
		}

		bool res = Stack.empty() ? true : false;
		return res;
	}
};

