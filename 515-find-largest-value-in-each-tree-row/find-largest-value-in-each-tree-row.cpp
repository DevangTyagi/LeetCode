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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int maxi = q.front()->val;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* top = q.front();
                q.pop();
                maxi = max(top->val,maxi);
                if(top->left != nullptr)
                q.push(top->left);
                if(top->right != nullptr)
                q.push(top->right); 
            }
            ans.push_back(maxi);
        }
        return ans;        
    }
};