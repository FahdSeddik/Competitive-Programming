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
    string solve(TreeNode* root,vector<TreeNode*>&ans, map<string,int> &mp){
        if(!root) return "%";
        string l = solve(root->left,ans,mp);
        string r = solve(root->right,ans,mp);
        string s = to_string(root->val) +"%"+l+"%"+r;
        if(mp[s]==1){
            ans.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        map<string,int> mp;
        if(!root) return ans;
        solve(root,ans,mp);
        return ans;
    }
};