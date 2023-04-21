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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        if(!root)  return ans;
        q.push({root,0});
        while(!q.empty()){
            int first,last;
            int qsize = q.size();
            int subval = q.front().second;
            for(int i=0; i<qsize ; i++){
                TreeNode* curnode = q.front().first;
                unsigned int curid = q.front().second-subval;
                q.pop();
                if(i==0) first = curid;
                if(i==qsize-1) last = curid;
                if(curnode->left) q.push({curnode->left,2*(curid)});
                if(curnode->right) q.push({curnode->right,2*(curid)+1});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};