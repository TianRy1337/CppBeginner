#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int l=0,r=1;
        //  while(l<nums.size())
        //  {
        //     if(nums[r]==target-nums[l])
        //     {
        //         break;
        //     }
        //     else if(r==nums.size()-1) 
        //     {
        //         l++;
        //         r=l+1;
        //     }
        //     else
        //     {
        //         r++;
        //     }
        // }
        // return {l,r};
        unordered_map<int, int> table;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(table.find(nums[i]) != table.end()){
                return {table[nums[i]], i};
            }
            table.insert({target - nums[i], i});
        }
        return nums;
    }
};

int main(){
    Solution _Solve = Solution();
    vector<int> _vec = {1, 2, 3, 4, 5};
    int _target{8};
    vector<int> _vec2 = _Solve.twoSum(_vec, _target);
    cout << "[";
    for(auto i = 0; i<_vec2.size(); i++){
        cout << _vec2[i] <<(i < _vec2.size()-1?", ":"");
    }
    cout << "]" << endl;
}
