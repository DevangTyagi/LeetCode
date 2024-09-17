/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string str = "";
        if(root==nullptr) return str;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*temp = q.front();
            q.pop();
            if(temp==nullptr) 
            str.append("null,");
            else
            {
              str.append(to_string(temp->val) + ',');
              q.push(temp->left);
              q.push(temp->right);
            }         
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
       if(data.size()==0)
       return nullptr;
       stringstream s(data);
       string str;
       getline(s,str,',');
       TreeNode *root = new TreeNode(stoi(str));
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty())
       {
        TreeNode*temp = q.front();
        q.pop();
        getline(s,str,',');
        if(str=="null"){
            temp->left=nullptr;
        }
        else{
           TreeNode *node = new TreeNode(stoi(str));
           temp->left=node;
           q.push(node);
        }

        getline(s,str,',');
        if(str=="null"){
            temp->right=nullptr;
        }
        else{
           TreeNode *node = new TreeNode(stoi(str));
           temp->right=node;
           q.push(node);
        }
       }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));