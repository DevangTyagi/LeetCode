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
    int depth_of_Balanced_tree(TreeNode*root)
    {
        if(root==nullptr)
        return 0;
        int left = depth_of_Balanced_tree(root->left);
        int right = depth_of_Balanced_tree(root->right);
        if(abs(left-right)>1)
        return -1;
        if(left==-1 || right==-1)
        return -1;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) 
    {
        if(root==nullptr)
        return true;
        if(depth_of_Balanced_tree(root)==-1) return false;
        return true;      
    }
};