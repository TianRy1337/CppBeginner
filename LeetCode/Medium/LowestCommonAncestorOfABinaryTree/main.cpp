#include<iostream>
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode *_left = lowestCommonAncestor(root->left,p,q);
        TreeNode *_right = lowestCommonAncestor(root->right,p,q);

        if(_left != NULL && _right != NULL){
            return root;
        }

        if(_left != NULL )return _left;
        return _right;
    }
};

int main(){
    Solution Solve = Solution();
    TreeNode Root = TreeNode(3);
    TreeNode left = TreeNode(5);
    TreeNode right = TreeNode(1);
    Root.left = &left;
    Root.right = &right;

    TreeNode left2 = TreeNode(6);
    TreeNode right2 = TreeNode(2);

    Root.left->left = &left2;
    Root.left->right = &right2;

    TreeNode left3 = TreeNode(0);
    TreeNode right3 = TreeNode(8);

    Root.right->left = &left3;
    Root.right->right = &right3;

    TreeNode *Ans = Solve.lowestCommonAncestor(&Root, Root.left->left, Root.right->right);
    return 0;
}
