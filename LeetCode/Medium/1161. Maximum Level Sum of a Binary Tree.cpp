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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi=INT_MIN,size=1,depth=0,ans=0;
        for(;!q.empty();size=q.size(),depth++){
            int temp=0;
            while(size--){
                auto x = q.front();q.pop();
                temp+=x->val;
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            if(temp>maxi)maxi=temp,ans=depth;
        }
        return ans+1;
    }
};