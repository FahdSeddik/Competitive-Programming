class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        vector<vector<int>> adjmat(n,vector<int>(n));
        for(const auto& r : roads){
            degree[r[0]]++,degree[r[1]]++;
            adjmat[r[0]][r[1]]++,adjmat[r[1]][r[0]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans,degree[i]+degree[j]-adjmat[i][j]);
            }
        }
        return ans;
    }
};