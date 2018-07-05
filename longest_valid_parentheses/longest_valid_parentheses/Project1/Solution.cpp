#include "Solution.h"
#include <stack>
#include <algorithm>
Solution::Solution()
{
}


Solution::~Solution()
{
}
int Solution::longestValidParentheses_stack(string s) {
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

int Solution::longestValidParentheses_dp(string s) {
	//dp.reserve(s.size());
	
	int Max = 0;
	dp.push_back(0);
	for (int i = 1; i < (int)s.size(); i++) {
		dp.push_back(0);
		if (s[i] == ')') {//()()
			if (s[i - 1] == '(') {
				if ((i - 2) < 0) {
					dp[i] = 2;
				}
				else {
					dp[i] = dp[i - 2] + 2;
				}
			}//(())
			else if (s[i - 1] == ')') {
				if (s[i - dp[i - 1] - 1] == '(') {
					dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];//()(())
				}
			}
			Max = max(dp[i], Max);
		}
	}
	return Max;
	//create vector<int> dp size = s
	//repeat s[i]
	//dp.push_back(0);
	//1. if s[i] == ')'
	//    1.1 "()()" if(s[i-1]=="(") dp[i] = dp[i-2] + 2 
	//    1.2 "(())" if (s[i-1]==")" && s[dp[i-1]-1] =="(") dp[i] = dp[i-1] +2;
	//    Max = max(dp[i],Max)
	//return Max
}