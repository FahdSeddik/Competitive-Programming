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
    unordered_map<int, vector<int>> mp;
public:
    void dfs(TreeNode* root){
        if(!root)return;
        if(root->left)mp[root->val].push_back(root->left->val),mp[root->left->val].push_back(root->val),dfs(root->left);
        if(root->right)mp[root->val].push_back(root->right->val),mp[root->right->val].push_back(root->val),dfs(root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        queue<int> q;
        unordered_set<int> vis;
        q.push(start),vis.insert(start);
        int size = 1, depth = 0;
        for(;!q.empty();size=q.size(),depth++){
            while(size--){
                int x = q.front();q.pop();
                for(int u : mp[x]){
                    if(vis.count(u))continue;
                    vis.insert(u),q.push(u);
                }
            }
        }
        return depth - 1;
    }
};