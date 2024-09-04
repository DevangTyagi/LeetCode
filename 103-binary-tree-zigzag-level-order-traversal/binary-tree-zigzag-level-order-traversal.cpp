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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
       bool left_to_right = true;
       queue<TreeNode*>q;
       vector<vector<int>> ans;
       if (root == nullptr) return ans;
       q.push(root);
       while(!q.empty())
       {
        int size = q.size();
        vector<int>mid(size);
        for(int i=0;i<size;i++)
        {
            TreeNode*temp = q.front();
            q.pop();
            int index = (left_to_right) ? i : (size-1-i);
            mid[index] = temp->val;
            if(temp->left!=nullptr) q.push(temp->left); 
            if(temp->right!=nullptr) q.push(temp->right); 
        }
        left_to_right = !left_to_right;
        ans.push_back(mid);
       } 
       return ans;
    }
};