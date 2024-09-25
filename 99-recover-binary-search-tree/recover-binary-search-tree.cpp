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

private:
     TreeNode*first;
     TreeNode*last;
     TreeNode*prev;

    void Inorder(TreeNode* root)
    {
      if(root == nullptr)
      return;
      Inorder(root->left);
      if(root->val < prev->val)
      {
        if(first == nullptr){
            first = prev;
            last = root;
        }
        else
        last = root;
      }
      prev = root;
      Inorder(root->right);
    }

public:      
    void recoverTree(TreeNode* root) 
    {    
     first = last = nullptr;
     prev = new TreeNode(INT_MIN);
     Inorder(root);
     if(first && last)
     swap(first->val , last->val);
    }
};