#include "Solution.h"
#include <stack>



Solution::Solution()
{
}


Solution::~Solution()
{
}

int Solution::longestValidParentheses(string s) {
	stack<char> cStack;
	int count = 0;
	char leftC = '(', rightC = ')';
	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cStack.push('(');
		}
		else if (s[i] == ')') {
			if (cStack.empty()) {
				continue;
			}
			else if (cStack.top() == '(') {
				cStack.pop();
				count+=2;
			}
			else {
				continue;
			}
		}
	}
	return count;
	//create a stack
	//create left char, right char
	//if s[i] = left, push
	//else if s[i] = right, 
	// - 1. if stack empty, skip 
	// - 2. else if stack.top = left char,pop, count++
	// - 3. else skip
	//else skip
}
