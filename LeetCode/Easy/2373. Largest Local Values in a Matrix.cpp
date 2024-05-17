class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++){
                ans[i-1][j-1] = max(max(max(grid[i][j],grid[i-1][j]), max(grid[i-1][j-1], grid[i][j-1])),
                max(max(max(grid[i+1][j], grid[i][j+1]), max(grid[i+1][j+1], grid[i+1][j-1])), grid[i-1][j+1]));
            }
        }
        return ans;
    }
};