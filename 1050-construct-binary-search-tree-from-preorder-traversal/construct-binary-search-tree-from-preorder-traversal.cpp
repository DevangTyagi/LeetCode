/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode*Solve(vector<int>& preorder,int &i ,int lower , int upper)
    {
        if(i==preorder.size() || preorder[i]<lower || preorder[i]>upper)
        return nullptr;
        TreeNode*root = new TreeNode(preorder[i++]);
        root->left = Solve(preorder,i,lower,root->val);
        root->right = Solve(preorder,i,root->val,upper);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
       return Solve(preorder,i,INT_MIN,INT_MAX);
    }
};