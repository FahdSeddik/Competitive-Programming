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
    int deepest;
    int sum;
public:
    void traverse(TreeNode* root,int level){
        if(!root)return;
        if(level>deepest)deepest=level,sum=0;
        if(deepest==level)sum+=root->val;
        traverse(root->left,level+1);
        traverse(root->right,level+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        deepest=-1;
        traverse(root,0);
        return sum;
    }
};