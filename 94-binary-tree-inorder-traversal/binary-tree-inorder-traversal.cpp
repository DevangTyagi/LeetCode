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
    vector<int> inorderTraversal(TreeNode* root) 
    {
     // Morris Traversal
     vector<int>ans;
     if(root==nullptr)
     return ans;
     TreeNode*curr = root;
     while(curr != nullptr)
     {
        if(curr->left == nullptr){
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode*node = curr->left;
            while(node->right && node->right != curr){
                node=node->right;
            }
            if(node->right==nullptr){
                node->right = curr;    //Creating a new Thread
                curr = curr->left;
            }
            else{
                node->right = nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
     }   
     return ans;
    }
};