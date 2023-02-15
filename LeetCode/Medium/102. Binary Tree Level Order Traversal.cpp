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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int size=1;
        for(;!q.empty();size=q.size()){
            vector<int> cur;
            while(size--){
                TreeNode* node = q.front();q.pop();
                int val = node->val;
                cur.push_back(val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};