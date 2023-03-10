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
    int ts;
    bool ans;
public:
    void dfs(TreeNode* root,int s=0){
        if(ans)return;
        if(!root)return;
        if(!root->left && !root->right){
            ans=max(ts==(s+root->val),ans);
            return;
        }
        dfs(root->right,s+root->val);
        dfs(root->left,s+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        ts=targetSum,ans=false;
        dfs(root);
        return ans;
    }
};