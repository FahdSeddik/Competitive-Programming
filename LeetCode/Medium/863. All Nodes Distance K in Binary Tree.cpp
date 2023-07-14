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
    vector<int> ans;
    vector<vector<int>> adj;
    vector<int> vis;
public:
    void createAdj(TreeNode* root){
        if(!root)return;
        if(root->left){
            adj[root->left->val].push_back(root->val);
            adj[root->val].push_back(root->left->val);
            createAdj(root->left);
        }
        if(root->right){
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
            createAdj(root->right);
        }
    }
    void dfs(int src,int& k,int depth=0){
        vis[src]=1;
        if(depth==k){
            ans.push_back(src);
            return;
        }
        for(auto u : adj[src]){
            if(!vis[u]){
                dfs(u,k,depth+1);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!target || !root)return {};
        adj.resize(501),vis.resize(501,0);
        createAdj(root);
        dfs(target->val,k);
        return ans;
    }
};