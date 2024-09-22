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
int count = 0;

    void Inorder(TreeNode* root ,int k ,int &result)
    {
        if(root==nullptr) 
        return;
        Inorder(root->left,k,result);
        count++;
        if(count == k)
        {
            result = root->val;
            return;
        }
        Inorder(root->right,k,result);
    }
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        Inorder(root,k,result);
        return result;
    }
};