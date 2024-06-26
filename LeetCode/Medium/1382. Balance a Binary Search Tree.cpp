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
    vector<int> inorder;
public:
    void traverse(TreeNode* root){
        if(!root)return;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }
    TreeNode* construct(TreeNode* root, int l, int r){
        if(!root || l>r)return nullptr;
        int mid=(r-l)/2+l;
        root->val=inorder[mid];
        root->left=construct(new TreeNode(),l,mid-1);
        root->right=construct(new TreeNode(),mid+1,r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        return construct(root,0,inorder.size()-1);
    }
};