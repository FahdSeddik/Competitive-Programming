class Solution {
public:
    double soupServings(int n) {
        if (n > 5000) return 1;
        n = (n + 24) / 25;
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1e9));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 and j == 0) {
                    dp[i][j] = 0.5;
                } else if (i == 0) {
                    dp[i][j] = 1;
                } else if (j == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = (dp[max(i - 4, 0)][j] + dp[max(i - 3, 0)][max(j - 1, 0)] + dp[max(i - 2, 0)][max(j - 2, 0)] + dp[max(i - 1, 0)][max(j - 3, 0)]) / 4;
                }
            }
        }
        return dp[n][n];
    }
};