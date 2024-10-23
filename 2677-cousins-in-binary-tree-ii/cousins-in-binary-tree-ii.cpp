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
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        if(root == nullptr)
        return nullptr;
       vector<int>level_sum;
       level_sum.push_back(root->val);
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty())
       {
        int sum = 0;
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode*node = q.front();
            q.pop();
            if(node->left != nullptr){
            q.push(node->left);
            sum += node->left->val;
            }            
            if(node->right){
                q.push(node->right);
                sum += node->right->val;
            }
        }
        level_sum.push_back(sum);
       }   
       q.push(root);
       root->val = 0;
       int lvl = 1;
       while(!q.empty())
       {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
          TreeNode*node = q.front();
          q.pop();
          int sib_sum = 0;
          sib_sum += node->left != nullptr ?  node->left->val : 0;
          sib_sum += node->right != nullptr ? node->right->val : 0;

           if(node->left){
           node->left->val = level_sum[lvl] - sib_sum ;
           q.push(node->left);
           }
           if(node->right){
            node->right->val = level_sum[lvl] - sib_sum ;
            q.push(node->right);
           }
        }   
        lvl++;     
       }
      return root;
    }
};