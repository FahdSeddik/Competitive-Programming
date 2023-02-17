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
private:
    TreeNode* previous = nullptr;
    int min = INT_MAX;
public:
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        return min;
    }
    void inOrder(TreeNode* root) {
        if (root == nullptr) return;
        inOrder(root->left);
        if (previous != nullptr) {
            min = std::min(min, root->val - previous->val);
        }
        previous = root;
        inOrder(root->right);
    }
};