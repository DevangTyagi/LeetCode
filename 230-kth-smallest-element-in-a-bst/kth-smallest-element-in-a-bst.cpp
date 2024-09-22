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
    int kthSmallest(TreeNode* root, int k) 
    {
        queue<TreeNode*>q;
        priority_queue<int>pq;
        if(root==nullptr) return -1;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*temp = q.front();
            q.pop();
            pq.push(temp->val);
            while(pq.size()>k){
                pq.pop();
            }
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        return pq.top();
    }
};