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
    void dfs(TreeNode* root,int cur=0){
        if(!root)return;
        cur*=10;
        cur+=root->val;
        if(!root->left && !root->right){
            ans+=cur;
            return;
        }
        dfs(root->left,cur);
        dfs(root->right,cur);

    }
    int sumNumbers(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
};