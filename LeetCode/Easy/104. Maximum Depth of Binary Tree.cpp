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
    int ans;
public:
    void dfs(TreeNode* root,int depth){
        if(!root)return;
        if(depth>ans)ans=depth;
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        ans=1;
        dfs(root,1);
        return ans;
    }
};