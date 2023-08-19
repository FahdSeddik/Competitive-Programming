class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int mod = 1e9 + 7;
        int dp[goal + 1][n + 1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1; i <= goal; ++i) {
            for(int j = 1; j <= n; ++j) {
                dp[i][j] = (1ll * dp[i - 1][j - 1] * (n - j + 1)) % mod;
                if(j - k >= 0) {
                    dp[i][j] += (1ll * dp[i - 1][j] * (j - k)) % mod;
                    dp[i][j] %= mod;
                }
            }
        }
        return dp[goal][n];
    }
};