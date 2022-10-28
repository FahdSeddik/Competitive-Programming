class Solution {
    int n,m;
    vector<int> dx{0,0,1,-1}, dy{1,-1,0,0};
    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(dp[i][j]!=1) return dp[i][j];
        int mx = 0;
        for(int k = 0;k<4;k++){
            int c = j + dx[k];
            int r = i + dy[k];
            if(r<0 || c<0 || c>=n || r>=m)continue;
            if(matrix[r][c]<matrix[i][j]) mx = max(mx,dfs(r,c,matrix,dp));
        }
        return dp[i][j] = mx + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(),n = matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(dp[i][j]==1) ans = max(ans,dfs(i,j,matrix,dp));
            }
        } 
        return ans;
    }
};