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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int size=1,depth=0;
        for(;!q.empty();depth++,size=q.size()){
            vector<int> cur;
            while(size--){
                TreeNode* node = q.front();q.pop();
                cur.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(depth%2==1)reverse(cur.begin(),cur.end());
            ans.push_back(cur);
        }
        return ans;
    }
};