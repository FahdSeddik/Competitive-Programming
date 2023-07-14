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
    int ans=INT_MAX;
public:
    void dfs(TreeNode* root,int depth=1){
        if(!root)return;
        if(!root->left && !root->right){
            ans=min(ans,depth);
            return;
        }
        if(depth>ans)return;
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        dfs(root);
        return ans;
    }
};