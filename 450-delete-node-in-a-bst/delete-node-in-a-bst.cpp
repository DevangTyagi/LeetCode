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
    TreeNode* Solve(TreeNode* root)
    {
      if(root->left==nullptr)
      return root->right;
      if(root->right==nullptr)
      return root->left;
      TreeNode*rightchild = root->right;
      TreeNode*leftchild = root->left;
      root=root->left;
      while(root->right){
        root=root->right;
      }
      root->right = rightchild;
      return leftchild;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==nullptr)
        return nullptr;
        if(root->val == key)
        return Solve(root);

        TreeNode*temp = root;
        while(temp)
        {
            if(temp->val > key ){
                if(temp->left != nullptr && temp->left->val == key){
                  temp->left = Solve(temp->left);
                  break;
                }
                else
                temp = temp->left;
            }
            else{
             if(temp->right != nullptr  && temp->right->val == key){
                temp->right = Solve(temp->right);
                break;
             }
             else
             temp=temp->right;
            }
        }
        return root;
    }
};