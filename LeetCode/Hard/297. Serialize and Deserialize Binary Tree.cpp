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
    string serialize(TreeNode* root) {
        if(!root)return "";
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* ptr = q.front();q.pop();
            if(!ptr)ans+="|,";
            else{
                ans+=to_string(ptr->val)+",";
                q.push(ptr->left),q.push(ptr->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* a=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="|") a->left=NULL;
            else{
                a->left=new TreeNode(stoi(str));
                q.push(a->left);
            }
            getline(s,str,',');
            if(str=="|") a->right=NULL;
            else{
                a->right=new TreeNode(stoi(str));
                q.push(a->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));