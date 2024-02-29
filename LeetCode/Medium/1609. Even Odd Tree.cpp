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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int size = 1,depth=0;
        for(;!q.empty();size=q.size(),depth++){
            int val = depth%2==0 ? INT_MIN:INT_MAX;
            while(size--){
                TreeNode* u = q.front();q.pop();
                if(depth%2==0 && (val>=u->val || u->val%2==0))return false;
                else if(depth%2!=0 && (val<=u->val || u->val%2!=0))return false;
                val=u->val;
                if(u->left)q.push(u->left);
                if(u->right)q.push(u->right);
            }
        }
        return true;
    }
};