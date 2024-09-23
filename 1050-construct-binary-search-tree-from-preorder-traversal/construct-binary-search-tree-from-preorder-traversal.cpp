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
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
       TreeNode*root = new TreeNode(preorder[0]);
       vector<int>mini;
       vector<int>maxi;
       for(int i=1;i<preorder.size();i++)
       {
        if(preorder[i]<root->val) 
        mini.push_back(preorder[i]);
        else 
        maxi.push_back(preorder[i]);
       }
       if(mini.size()>0)
       root->left = bstFromPreorder(mini);
       if(maxi.size()>0)
       root->right = bstFromPreorder(maxi);
       return root;
    }
};