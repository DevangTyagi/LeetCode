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
    void InorderBST(TreeNode*root,vector<int>&ans)
    {
        if(root==nullptr)
        return;
        InorderBST(root->left,ans);
        ans.push_back(root->val);
        InorderBST(root->right,ans);
    }

    bool findTarget(TreeNode* root, int k) 
    {
        vector<int>ans;
        InorderBST(root,ans);
        int low=0 , high=ans.size()-1;
        while(low<high)
        {
            int sum = ans[low]+ans[high];
            if(sum == k)
            return true;
            else if(sum < k)
            low++;
            else
            high--;
        }
        return false;
    }
};