class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(n+1, vector<int>(minProfit+1));
        auto new_dp=dp;
        for(int i = 0; i<=n; i++) {
            dp[i][0] = 1;
        }
        for(int i = (int)group.size()-1; i>= 0; i--) {
            for(int j = 0; j<=n; j++) {
                for(int p = 0; p <= minProfit; p++) {
                    int not_taken = dp[j][p];
                    int taken = 0;
                    if(group[i] <= j) {
                        taken = dp[j - group[i]][max(0, p - profit[i])];   
                    }
                    new_dp[j][p] = (taken + not_taken) % MOD;
                }
            }
            swap(dp, new_dp);
            
        }
        return dp[n][minProfit];
    }
};