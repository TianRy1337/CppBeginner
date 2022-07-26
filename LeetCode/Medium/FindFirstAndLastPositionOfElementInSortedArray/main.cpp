#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        /// MyOwn
        // vector<int> ansVec {};
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i<nums.size(); i++){
        //     if(nums[i] == target){
        //         ansVec.push_back(i);
        //     }
        // }
        // if(ansVec.size() == 1 ){
        //     ansVec.push_back(ansVec[0]);
        // }else if( ansVec.size() == 0){
        //     return {-1,-1};
        // }
        // return {ansVec[0],ansVec[ansVec.size()-1]};
        


        ///Time Complexity :- O(Log(n))
        /// Space Complexity :- O(1)
        auto low = lower_bound(nums.begin(),nums.end(),target);
        auto up = upper_bound(nums.begin(),nums.end(),target);
        
        if(!binary_search(nums.begin(),nums.end(),target))    return {-1,-1};
        
        int first = low - nums.begin();
        int last = up - nums.begin()-1;
        
        return {first ,last};
    }
};

int main(){
    Solution Solve = Solution();
    vector<int> Input{5,7,7,8,8,10};
    vector<int> Tmp = Solve.searchRange(Input,8);

    for (auto x : Tmp)
        cout << x << " ";
    return 0;
}
