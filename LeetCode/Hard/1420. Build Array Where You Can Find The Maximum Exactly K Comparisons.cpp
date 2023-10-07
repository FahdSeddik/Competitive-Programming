class Solution {
    const int MOD = 1e9+7;
    vector<vector<vector<int>>> dp;
    int N,M,K;
public:
    int solve(int n=0,int m=0,int k=0){
        if(n==N)return k==K;
        if(k>K)return 0;
        if(dp[n][m][k]!=-1)return dp[n][m][k];
        int ans=0;
        for(int i=1;i<=M;i++){
            if(i>m)ans=(ans+solve(n+1,i,k+1))%MOD;
            else ans=(ans+solve(n+1,m,k))%MOD;
        }
        return dp[n][m][k]=ans%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N=n,M=m,K=k;
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return solve();
    }
};