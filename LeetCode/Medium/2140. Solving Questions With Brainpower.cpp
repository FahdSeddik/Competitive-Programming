class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        long long dp[n + 1];
        memset(dp,0,sizeof(dp));
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = max(q[i][0] + dp[min(i + q[i][1] + 1, n)], dp[i + 1]);
        }
        return dp[0];
    }
};