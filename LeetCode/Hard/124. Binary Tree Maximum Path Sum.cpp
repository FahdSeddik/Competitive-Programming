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
    int submx;
public:
    int helper(TreeNode* root){
        if(!root)return -1e5;
        if(!root->left && !root->right)return root->val;
        int left=helper(root->left);
        int right=helper(root->right);
        int curmax=max(root->val,max(root->val+left,root->val+right));
        if(left>curmax)submx=max(submx,left);
        if(right>curmax)submx=max(submx,right);
        if(right+left+root->val>curmax)submx=max(submx,right+left+root->val);
        return curmax;
    }
    int maxPathSum(TreeNode* root) {
        submx=INT_MIN;
        return max(helper(root),max(root->val,submx));
    }
};