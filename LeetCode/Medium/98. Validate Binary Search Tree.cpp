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
    bool isValidBST(TreeNode* root,long low=LONG_MIN,long high=LONG_MAX) {
        if(!root)return true;
        if((root->val < high) && (root->val > low)){
          return (isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high));
        }else{
            return false;
        }
    }
};