class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(k+1,vector<int>(2));
        for(int i=0;i<=k;i++)dp[i][0]=INT_MAX;
        for(auto& p : prices){
            for(int i=1;i<=k;i++){
                dp[i][0]=min(dp[i][0],p-dp[i-1][1]);
                dp[i][1]=max(dp[i][1],p-dp[i][0]);
            }
        }
        return dp[k][1];
    }
};