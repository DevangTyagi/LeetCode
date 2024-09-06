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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int>ans;
        if(root==nullptr)
        return ans;
        map<int,TreeNode*>mpp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(!q.empty())
        {
            auto itr = q.front();
            q.pop();
            TreeNode*temp = itr.first;
            int Hline = itr.second;
            if(mpp.find(Hline)!=mpp.end())
            {
                mpp.erase(Hline);
            }
            mpp[Hline]=temp;
            if(temp->left!=nullptr)
            q.push({temp->left,Hline+1});
            if(temp->right!=nullptr)
            q.push({temp->right,Hline+1});
        }
        for(auto itr : mpp)
        ans.push_back(itr.second->val);

        return ans;
    }
};