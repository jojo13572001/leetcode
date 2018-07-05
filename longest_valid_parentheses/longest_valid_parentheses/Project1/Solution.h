#pragma once
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
Solution();
	~Solution();
	int longestValidParentheses_stack(string s);
	int longestValidParentheses_dp(string s);
private:
	vector<int> dp;
};

