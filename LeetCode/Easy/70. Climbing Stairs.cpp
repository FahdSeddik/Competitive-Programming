class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(46,-1);
        dp[0]=0;
        dp[1]=1,dp[2]=2,dp[3]=3;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};