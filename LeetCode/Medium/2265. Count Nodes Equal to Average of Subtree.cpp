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
    int getAvg(TreeNode* root,int& cnt,int& sum){
        if(!root)return 0;
        int lcnt=0,lsum=0,rcnt=0,rsum=0;
        int leftSubtree = getAvg(root->left,lcnt,lsum);
        int rightSubtree = getAvg(root->right,rcnt,rsum);
        cnt+=lcnt+rcnt+1,sum+=lsum+rsum+root->val;
        return ((lsum+rsum+root->val)/(lcnt+rcnt+1) == root->val)+leftSubtree+rightSubtree;
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0,sum=0;
        return getAvg(root,cnt,sum);
    }
};