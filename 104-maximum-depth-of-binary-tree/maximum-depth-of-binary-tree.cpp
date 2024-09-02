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
    void solve(TreeNode*temp,int &ans,int count)
    {
        if(temp==nullptr)
        {
            ans=max(ans,count);
            return;
        }
        solve(temp->left,ans,count+1);
        solve(temp->right,ans,count+1);

    }
    int maxDepth(TreeNode* root) {
        int ans = 0;
        if(root==nullptr)
        return ans;
        TreeNode*temp=root;
        solve(temp,ans,0); 
        return ans;
    }
};