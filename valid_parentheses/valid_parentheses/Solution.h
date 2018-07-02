#pragma once
//#include "stdafx.h"
#include <String>
#include <stack>

using namespace std;
class Solution {
public:
	bool isValid(std::string s){
		//create two strings
		std::string leftParentheses = "({[";
		std::string rightParentheses = ")}]";
		//create stack
		std::stack<char> sStack;
		//repeat string size
		for (unsigned int i = 0; i < s.size(); i++) {
//			cout << "string: "<<s[i]<<std::endl;
			if (leftParentheses.find(s[i]) != std::string::npos) {
				//cout << "push " << s[i] << std::endl;
				sStack.push(s[i]);
			}
			else if (rightParentheses.find(s[i] != std::string::npos)) {
				if (sStack.empty()) {
					//cout << "stack empty" << std::endl;
					return false;
				}
				else if (leftParentheses.find(sStack.top()) == rightParentheses.find(s[i])) {
					//cout << "pop" << s[i] << std::endl;
					sStack.pop();
				}
				else {
					//cout << sStack.top()<<" not correspond to " << s[i] << std::endl;
					return false;
				}
			}
			else {
				//cout << "no such character "<<s[i] << std::endl;
				return false;
			}
		}
		if (sStack.empty()) {
			return true;
		}
		else {
			return false;
		}
		//if 1. s[i] is left parnetheses, push		//push s[i] to stack, check top with s[i]

		//else if 2. s[i] is right parentheses
		//    - 2.1 stack is empty, fail
		//	  - 2.2 top is right parentheses, fail
		//	  - 2.3 top is left parentheses but not corresponding one, fail
		//	  - 2.4 top is left parentheses and corresponding one, pop top
	}
}; 
