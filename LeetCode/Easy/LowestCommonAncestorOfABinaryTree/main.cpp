//235. Lowest Common Ancestor of a Binary Search Tree
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if (root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }
        
    }
};

int main(){
    TreeNode Root = TreeNode(6);
    TreeNode left = TreeNode(2);
    TreeNode right = TreeNode(8);
    Root.left = &left;
    Root.right = &right;

    TreeNode left2 = TreeNode(0);
    TreeNode right2 = TreeNode(4);

    Root.left->left = &left2;
    Root.left->right = &right2;

    TreeNode left3 = TreeNode(7);
    TreeNode right3 = TreeNode(9);

    Root.right->left = &left3;
    Root.right->right = &right3;

    Solution Solve = Solution();
    TreeNode *Ans = Solve.lowestCommonAncestor(&Root, Root.left->left, Root.right->right);

    return 0;
}
