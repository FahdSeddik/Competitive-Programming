class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m),cols(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rows[i]+=grid[i][j];
                cols[j]+=grid[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=rows[i]+cols[j]-(n-rows[i])-(m-cols[j]);
            }
        }
        return grid;
    }
};
