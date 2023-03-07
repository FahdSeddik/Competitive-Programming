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
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int size=1,depth=0;
        for(;!q.empty();size=q.size(),++depth){
            int mx = INT_MIN;
            while(size--){
                TreeNode* cur = q.front();q.pop();
                mx = max(mx,cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};