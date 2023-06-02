class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(3,vector<int>(2));
        for(int i=0;i<=2;i++)dp[i][0]=INT_MAX;
        for(auto& p : prices){
            for(int i=1;i<=2;i++){
                dp[i][0]=min(dp[i][0],p-dp[i-1][1]);
                dp[i][1]=max(dp[i][1],p-dp[i][0]);
            }
        }
        return dp[2][1];
    }
};