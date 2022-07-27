#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {

    }
};

void printNode(TreeNode* root){
    if(root->val != NULL){
        cout << root->val << " ";
    }
    if(root->left != NULL){
        printNode(root->left);
    }
    if(root->right != NULL){
        printNode(root->right);
    }
}

int main (){
    Solution Solve = Solution();
    TreeNode Root = TreeNode(1);
    TreeNode left = TreeNode(2);
    TreeNode right = TreeNode(5);
    Root.left = &left;
    Root.right = &right;

    TreeNode left2 = TreeNode(3);
    TreeNode right2 = TreeNode(4);

    Root.left->left = &left2;
    Root.left->right = &right2;

    TreeNode left3 = TreeNode(6);
    TreeNode right3 = TreeNode(7);

    Root.right->left = &left3;
    Root.right->right = &right3;
    cout << "[ " ;
    printNode(&Root);
    cout << "]" << endl;

    return 0;
}
