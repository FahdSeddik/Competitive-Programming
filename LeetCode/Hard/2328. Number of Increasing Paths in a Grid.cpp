constexpr int MOD {1000000007};
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    int dp[1000][1000]{};
public:
    int solve(vector<vector<int>>& grid, int i, int j, int prev) {
        if(i >= grid.size() || i < 0) return 0;
        if(j >= grid[0].size() || j < 0) return 0;
        if(prev >= grid[i][j]) return 0;
        if(dp[i][j] > 0) return dp[i][j];
        int ans{1};        
        prev = grid[i][j];
        ans = (ans + solve(grid, i+1, j, prev)) % MOD;
        ans = (ans + solve(grid, i-1, j, prev)) % MOD;
        ans = (ans + solve(grid, i, j+1, prev)) % MOD;
        ans = (ans + solve(grid, i, j-1, prev)) % MOD;
        return dp[i][j] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans{};
        for(int i = 0; i < rows; ++i)
            fill_n(&dp[i][0], cols, 0);
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                ans = (ans + solve(grid, i, j, 0)) % MOD;
            }
        }
        return ans;
    }
};