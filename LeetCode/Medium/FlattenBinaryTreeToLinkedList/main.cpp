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
    
    TreeNode* rightmost(TreeNode* root){
        if (root->right==NULL) return root;
        return rightmost(root->right);
    }
    
    void flatten(TreeNode* root) {
        if (root==NULL) return;
        TreeNode* nextright;
        TreeNode* rightMOST;
        
        while (root){
            
            if (root->left){
                rightMOST = rightmost(root->left);
                nextright = root->right;
                root->right = root->left;
                root->left=NULL;
                rightMOST->right=nextright;
            }
            root=root->right;
        }
    }
};

void printNode(TreeNode* root){
    if(root->val != NULL){
        cout << root->val << " ";
    }
    if(root->left != NULL &&root->right != NULL){
        printNode(root->left);
        printNode(root->right);
    }
    if(root->left == NULL &&root->right != NULL){
        cout << "null ";
        printNode(root->right);
    }
    else if(root->left != NULL &&root->right == NULL){
        printNode(root->left);
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

    // TreeNode right3 = TreeNode(6);
    
    // Root.right->right = &right3;

    cout << "[ " ;
    printNode(&Root);
    cout << "]" << endl;
    

    Solve.flatten(&Root);

    cout << "[ " ;
    printNode(&Root);
    cout << "]" << endl;
    // TreeNode Root = TreeNode(1);
    // TreeNode Right = TreeNode(2);
    // TreeNode Right1 = TreeNode(3);
    // TreeNode Right2 = TreeNode(4);
    // TreeNode Right3 = TreeNode(5);
    // TreeNode Right4 = TreeNode(6);
    // Root.right = &Right;
    // Right.right = &Right1;
    // Right1.right = &Right2;
    // Right2.right = &Right3;
    // Right3.right = &Right4;
    // printNode(&Root);

     return 0;
}
