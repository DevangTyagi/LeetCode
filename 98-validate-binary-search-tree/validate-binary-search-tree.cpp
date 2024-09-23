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
    bool isValidBST(TreeNode* root,long long minvalue,long long maxvalue)
    {
     if(root==nullptr)
     return true;
     if(root->val <= minvalue || root->val >= maxvalue)
     return false;   // Excluded from range for current node
     return isValidBST(root->left,minvalue,root->val) && isValidBST(root->right,root->val,maxvalue);
    }
    bool isValidBST(TreeNode* root) 
    {
        if(root==nullptr)
        return true;
        else
        return isValidBST(root,LLONG_MIN,LLONG_MAX);
    }
};