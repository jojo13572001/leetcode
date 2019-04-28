//
//  main.cpp
//  1_two_sum
//
//  Created by Mac on 2019/4/28.
//  Copyright © 2019年 Mac. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> unorder;
        std::vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            unorder[nums[i]] = i;
        }
        
        for(int i=0; i<nums.size(); i++){
            int complent = target-nums[i];
            if(unorder.count(complent)>0 && unorder[complent]!=i){
                result.push_back(i);
                result.push_back(unorder[complent]);
                return result;
            }
        }
        return result;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }
    
    if (length == 0) {
        return "[]";
    }
    
    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    vector<int> nums = {3,3};
    int target = 6;
    vector<int> ret = Solution().twoSum(nums, target);
    string out = integerVectorToString(ret);
    cout << out << endl;
    return 0;
}
