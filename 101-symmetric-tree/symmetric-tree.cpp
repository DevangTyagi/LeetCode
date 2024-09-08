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
    bool isMirrorTree(TreeNode* p, TreeNode* q) 
    {
       if(p==nullptr || q==nullptr)
       return (p==q);  //If equal it will return true if both are different it will return false

       return (p->val == q->val) && isMirrorTree(p->left,q->right) && isMirrorTree(p->right,q->left);
    }

    bool isSymmetric(TreeNode* root)
    {
       if(root==nullptr) return true;
       TreeNode*left = root->left;
       TreeNode*right = root->right;
       return isMirrorTree(left,right);
    }
};