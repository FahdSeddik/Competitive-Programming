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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ptr = root;
        TreeNode* parent = NULL;
        while(ptr){
            parent = ptr;
            if(ptr->val >val)ptr=ptr->left;
            else ptr=ptr->right;
        }
        if(!parent){
            root= new TreeNode(val);
        }else if(parent->val > val)parent->left = new TreeNode(val);
        else parent->right = new TreeNode(val);
        return root;
    }
};