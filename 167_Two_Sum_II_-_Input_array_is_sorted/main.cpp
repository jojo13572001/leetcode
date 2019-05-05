class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idxFront=0, idxBack=numbers.size()-1;
        for(; idxFront<idxBack; idxFront++){
            int complement = target - numbers[idxFront];
            for(; idxBack>idxFront; idxBack--){
                if(numbers[idxBack]==complement){
                    return vector<int>{idxFront+1, idxBack+1};
                }else if(numbers[idxBack]<complement){
                    break;
                }else{
                    continue;
                }
            }
        }
        return vector<int>{};
    }
};