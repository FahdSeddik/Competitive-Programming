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
    queue<int> l;
    bool f=true;
public:
    void dfs1(TreeNode* root){
        if(!root)return;
        if(root->left)dfs1(root->left);
        if(root->right)dfs1(root->right);
        else if(!root->left)l.push(root->val);
    }
    void dfs2(TreeNode* root){
        if(!f || !root)return;
        if(root->left)dfs2(root->left);
        if(root->right)dfs2(root->right);
        else if(!root->left){
            if(l.empty() || l.front()!=root->val)f=false;
            l.pop();
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs1(root1),dfs2(root2);
        return f && l.empty();
    }
};