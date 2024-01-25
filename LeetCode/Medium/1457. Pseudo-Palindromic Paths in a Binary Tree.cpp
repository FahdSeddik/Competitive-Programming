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
    int solve(TreeNode* root,int*prev=nullptr){
        if(!root)return 0;
        if(!prev)prev=new int[10],memset(prev,0,sizeof(int)*10);
        prev[root->val]++;
        int cr=solve(root->right,prev),cl=solve(root->left,prev);
        if(!root->right && !root->left){
            int cnt=0,s=0;
            for(int i=1;i<=9;i++)if(prev[i])s+=prev[i],cnt+=prev[i]%2==1;
            prev[root->val]--;
            cout<<cnt<<" "<<s<<endl;
            if(cnt>1)return 0;
            return 1;
        }
        prev[root->val]--;
        return cl+cr;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return solve(root);
    }
};