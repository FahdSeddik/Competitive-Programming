class Solution {
public:

    int tribonacci(int n) {
        int dp[38];
        dp[0]=0,dp[1]=dp[2]=1;
        for(int i=3;i<=37;i++)dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
        return dp[n];
    }
};