#include "Solution.h"
#include <stack>
#include <algorithm>

Solution::Solution()
{
}


Solution::~Solution()
{
}
int Solution::longestValidParentheses(string s) {
	stack<int> cStack;
	int Max = 0;
	cStack.push(-1);
	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] == '('){
			cStack.push(i);
		}
		else if (s[i] == ')') {
			if(cStack.top()>-1 && s[cStack.top()] == '('){
				cStack.pop();
				Max = max((int)i - cStack.top() , Max);
			}
			else {
				cStack.push(i);
			}
		}
	}
	return Max;
	//create a stack
	//create max=0 
	//push -1 to stack
	//repeat s[i]
	//if s[i] = left char, push i
	//else if s[i] = right char
	// - 1. if stack.top = left char, pop , max= Max(i-stack[top], max)
	// - 2. else stack.push(i)
}
