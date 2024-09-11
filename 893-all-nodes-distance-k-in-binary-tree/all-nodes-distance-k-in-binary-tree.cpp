/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Fill_Parent_tracker(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&Parent_tracker){
       if(root== nullptr) return;
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty())
       {
        TreeNode*temp = q.front();
        q.pop();
        if(temp->left){
        Parent_tracker[temp->left] = temp;
        q.push(temp->left);
        }
        if(temp->right){
            Parent_tracker[temp->right] = temp;
            q.push(temp->right);
        }
       }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*,TreeNode*>Parent_tracker;
        Fill_Parent_tracker(root,Parent_tracker);
        map<TreeNode*,bool>Visited;
        queue<TreeNode*>q;
        q.push(target);
        Visited[target] = true;
        int distance = 0;
        while(!q.empty())
        {
            if(distance==k) break;
            distance++;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
             TreeNode*temp = q.front();
             q.pop();
             if(temp->left && !Visited[temp->left]){
                q.push(temp->left);
                Visited[temp->left] = true;
             }
             if(temp->right && !Visited[temp->right]){
              q.push(temp->right);
              Visited[temp->right]=true;
             }
             if(Parent_tracker[temp] && !Visited[Parent_tracker[temp]]){
               q.push(Parent_tracker[temp]);
              Visited[Parent_tracker[temp]]=true;
             }
            }
        }
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};