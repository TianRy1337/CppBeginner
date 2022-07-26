#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <memory>
using namespace std;
struct BSTNode{
    int val;
    int count;
    int left_count;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val): val(val), count(1), left_count(0), left{nullptr}, right{nullptr}{}
    ~BSTNode(){delete left; delete right;}
    int less_or_equal() const{return count +left_count;}
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> Ans{};
        int count{0};
        /// burte force time comp((n^2-1)/2)
        // for(int i = 0; i <nums.size(); i++){
        //     count = 0;
        //     for(int j = i+1; j<nums.size();j++){
        //         if(nums[i]>nums[j]){
        //             count++;
        //         }
        //         count++;
        //     }
        //     Ans.push_back(count);
        // }
        
        if(nums.empty())return{};
        std::reverse(nums.begin(), nums.end());
        std::unique_ptr<BSTNode> root(new BSTNode(nums[0]));
        vector<int> ans{0};
        for (int i = 1; i < nums.size(); ++i)
            ans.push_back(insert(root.get(), nums[i]));
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    // Returns the number of elements smaller than val under root.
    int insert(BSTNode* root, int val) {
        if (root->val == val) {
            ++root->count;
            return root->left_count;
        } else if (val < root->val) {
            ++root->left_count;
            if (root->left == nullptr) {
                root->left = new BSTNode(val);            
                return 0;
            } 
            return insert(root->left, val);
        } else  {
            if (root->right == nullptr) {
                root->right = new BSTNode(val);
                return root->less_or_equal();
            }
            return root->less_or_equal() + insert(root->right, val);
        }
    }
};

void printVec(vector<int> const &_vec){
    cout <<"[";
    for(int i=0; i<_vec.size(); i++){
        cout << _vec[i];
        i+1 < _vec.size()?cout<<", ":cout<<"";
    }
    cout <<"]";
}



int main(){
    Solution solution{};
    vector<int> myVec{5,2,6,1};
    printVec(myVec);
    vector<int> AnsVec = solution.countSmaller(myVec);
    printVec(AnsVec);
    cout << "\n";
    return 0;

}
