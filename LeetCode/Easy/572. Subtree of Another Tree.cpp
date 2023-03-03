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
    bool issame(TreeNode* root,TreeNode* subRoot){
        if(!root || !subRoot)return !root && !subRoot;
        if(root->val==subRoot->val)return issame(root->left,subRoot->left) && issame(root->right,subRoot->right);
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot)return !root && !subRoot;
        return issame(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};