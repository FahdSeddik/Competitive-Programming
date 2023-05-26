class Solution {
    int n;
    vector<int> p_sum;
    vector<vector<int>> dp;
public:
    int stoneGameII(vector<int>& p){
        n = p.size();
        dp.resize(n, vector<int>(n,-1));
        p_sum.resize(n+1,0);
        for(int i = 1 ; i <= n ; ++i){
            p_sum[i]=p_sum[i-1]+p[i-1];
        }
        return solve(0, 1);
    }
    int solve(int index, int m){
        if(index>=n)return 0;
        if(index+2*m>=n) return p_sum[n]-p_sum[index];
        if(dp[index][m]!=-1)return dp[index][m];
        int ans=INT_MAX;
        for(int i=1;i<=2*m;i++){
            ans=min(ans,solve(index+i,max(i, m)));
        }
        return dp[index][m]=p_sum[n]-p_sum[index]-ans;
    }
};