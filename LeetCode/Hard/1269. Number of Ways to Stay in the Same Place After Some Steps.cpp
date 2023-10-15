class Solution {
    vector<vector<int>> dp;
    const int MOD = 1e9+7;
public:
    int numWays(int steps, int arrLen) {
        int n = min(steps,arrLen);
        dp.resize(n+1,vector<int>(steps+1));
        dp[0][0]=1;
        for(int i=1;i<=steps;i++){
            for(int j=n-1;j>=0;j--){
                int res=dp[j][i-1];
                if(j<n-1)res=(res+dp[j+1][i-1])%MOD;
                if(j>0)res=(res+dp[j-1][i-1])%MOD;
                dp[j][i]=res;
            }
        }
        return dp[0][steps];
    }
};