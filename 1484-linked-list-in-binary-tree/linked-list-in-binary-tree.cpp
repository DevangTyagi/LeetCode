/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool valid_path(ListNode* head, TreeNode* root)
    {
        if(head==nullptr) return true;
        if(root==nullptr) return false;
        if(head->val==root->val)
        {
            return valid_path(head->next,root->left) || valid_path(head->next,root->right);
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        if(head==nullptr) return true;
        if(root==nullptr) return false;
        return valid_path(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};