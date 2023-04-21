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
    int maxLength=0;
    void dfs(TreeNode* root,int dir,int currLength){
        if(!root) return;
        maxLength=max(maxLength,currLength);
        dfs(root->left,0,dir?currLength+1:1);
        dfs(root->right,1,dir?1:currLength+1);
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,0,0);
        dfs(root,1,0);
        return maxLength;
    }
};