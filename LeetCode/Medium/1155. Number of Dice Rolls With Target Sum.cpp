class Solution {
    int k,target;
    int MOD = 1e9+7;
    int freq[31][1001];
public:
    int solve(int n, int tot=0){
        if(n==0)return tot==target;
        if(freq[n][tot]!=-1)return freq[n][tot];
        int ans=0;
        for(int i=1;i<=min(k,target-tot);i++){
            ans=(ans+solve(n-1,tot+i))%MOD;
        }
        return freq[n][tot]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        this->k=k,this->target=target;
        memset(freq,-1,sizeof(freq));
        return solve(n);
    }
};