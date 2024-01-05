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
    int findBottomLeftValue(TreeNode* root) {        
        queue<TreeNode*> q;
        q.push(root);
        int val=root->val,size=1;
        for(;!q.empty();size=q.size()){
            val=q.front()->val;
            while(size--){
                TreeNode* x = q.front();q.pop();
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
        }        
        return val;
    }
};