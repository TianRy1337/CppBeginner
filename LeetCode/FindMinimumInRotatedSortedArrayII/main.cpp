#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        //Solution 1 直接給最小值
        return *min_element(begin(nums), end(nums));

        //Solution 2 二分搜尋
        int left = 0;
        int right = nums.size()-1;
        while (left != right and nums[left] >= nums[right]){
            if(nums[left] > nums[right]){
                int mid = left + (right -left)/2;

                if (nums[left] <= nums[mid]){
                    left = mid +1;
                }else{
                    left = left +1;
                    right = mid;
                }
            }else{
                right = right -1;
            }
        }
        return nums[left];
    }
};

int main(){
    Solution solution{};
    vector<int> Input = {1,3,5,7};
    int minNum =solution.findMin(Input);
    cout << minNum;
    return 0;
}
