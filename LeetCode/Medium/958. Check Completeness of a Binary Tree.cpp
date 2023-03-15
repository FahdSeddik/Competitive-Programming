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
    bool isCompleteTree(TreeNode* root) {
        if(!root)return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty() && q.front()){
            q.push(q.front()->left);
            q.push(q.front()->right);
            q.pop();
        }
        while(!q.empty() && !q.front())q.pop();
        return q.empty();
    }
};