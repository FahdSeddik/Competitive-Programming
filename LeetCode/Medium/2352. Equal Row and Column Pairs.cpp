class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans = 0;
        map<vector<int>, int> m;
        int rows = grid.size(), cols = rows;
        for (int i=0; i<rows; i++) m[grid[i]]++;
        for (int i=0; i<grid[0].size(); ++i) {
            vector<int> vec;
            for (int j=0; j<rows; ++j) vec.push_back(grid[j][i]);
            ans += m[vec];
        }
        return ans;
    }
};