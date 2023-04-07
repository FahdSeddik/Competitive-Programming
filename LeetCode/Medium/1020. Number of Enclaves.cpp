class Solution {
    int m,n,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j){
        vis[i][j]=1;
        for(int d=0;d<4;d++){
            int r =i+dx[d],c=j+dy[d];
            if(r<0 || c<0 || r>=m || c>=n || vis[r][c] || !grid[r][c])continue;
            dfs(grid,vis,r,c);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n));
        for(int i=0;i<m;i++){
            if(!vis[i][0] && grid[i][0])dfs(grid,vis,i,0);
            if(!vis[i][n-1] && grid[i][n-1])dfs(grid,vis,i,n-1);
        }
        for(int i=0;i<n;i++){
            if(!vis[0][i] && grid[0][i])dfs(grid,vis,0,i);
            if(!vis[m-1][i] && grid[m-1][i])dfs(grid,vis,m-1,i);
        }
        int ans=0;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(!vis[i][j] && grid[i][j])ans++;
            }
        }
        return ans;
    }
};