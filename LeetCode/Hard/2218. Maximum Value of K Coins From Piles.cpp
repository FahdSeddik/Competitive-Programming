class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        int dp[n + 1][k + 1];
        memset(dp,0,sizeof(dp));
        for (int i = 0; i < n; i++) {
            partial_sum(piles[i].begin(),piles[i].end(),piles[i].begin());
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                for (int take = 1; take <= piles[i - 1].size() && take<=j; take++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - take] + piles[i - 1][take - 1]);
                }
            }
        }
        return dp[n][k];
    }
};