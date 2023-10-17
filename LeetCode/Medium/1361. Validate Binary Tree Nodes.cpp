class Solution {
    bool f=true;
    int nodes=0;
public:
    bool dfs(vector<int>&l,vector<int>&r,int src){
        int ch1=l[src],ch2=r[src];
        nodes++;
        l[src]=-2,r[src]=-2;
        if(ch1==-2 || ch2==-2)return f=false;
        if(ch1!=-1)dfs(l,r,ch1);
        if(ch2!=-1)dfs(l,r,ch2);
        return false;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> freq(n+1);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1)freq[leftChild[i]]++;
            if(rightChild[i]!=-1)freq[rightChild[i]]++;
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(freq[i]==0){
                root=i;
                break;
            }
        }
        if(root==-1)return false;
        dfs(leftChild,rightChild,root);
        return f && nodes==n;
    }
};