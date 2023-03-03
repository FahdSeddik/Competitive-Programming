class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<=1)return n;
        int dp[n+1];
        dp[0]=0,dp[1]=1;
        int ans = INT_MIN;
        for(int i=2;i<=n;i++){
            if(i%2)dp[i]=dp[i/2]+dp[(i/2)+1];
            else dp[i]=dp[i/2];
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};