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
    int solve(TreeNode* root, int sum=0){
        if(!root)return sum;
        root->val+=solve(root->right,sum);
        return solve(root->left,root->val);
    }
    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        return root;
    }
};