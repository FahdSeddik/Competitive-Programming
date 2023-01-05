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
    int check(TreeNode* root){
        if(!root)return 0;
        if(!root->left && !root->right)return 1;
        int lh=check(root->right),rh=check(root->left);
        if(lh==-1 || rh==-1 || abs(lh-rh)>1){
            return -1;
        }
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        return check(root)!=-1;
    }
};