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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = inorder.size()-1;
        return solve(inorder,postorder,i,0,i);
    }
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int&i,int l,int r){
        if(l>r)return 0;
        int x = r;
        while(postorder[i]!=inorder[x])x--;
        i--;
        TreeNode* root = new TreeNode(inorder[x]);
        root->right = solve(inorder,postorder,i,x+1,r);
        root->left = solve(inorder,postorder,i,l,x-1);
        return root;
    }
};;