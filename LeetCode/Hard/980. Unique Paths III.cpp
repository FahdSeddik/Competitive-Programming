class Solution {
    int n,m,obst;
    vector<vector<int>> dp;
    vector<int> dx{1,-1,0,0},dy{0,0,1,-1};
    vector<vector<bool>> vis;
public:
    int solve(vector<vector<int>>& grid,int i,int j,int walked=1){
        vis[i][j]=true;
        int ways=0;
        for(int d=0;d<4;d++){
            int r = dx[d]+i,c=dy[d]+j;
            if(r<0 || c<0 || r>=n || c>=m || vis[r][c] || grid[r][c]==-1)continue;
            if(grid[r][c]==2){
                ways+=(walked+1==n*m-obst);
            }else{
                ways+=solve(grid,r,c,walked+1);
            }            
        }
        vis[i][j]=false;
        return dp[i][j]=ways;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        vis.resize(n,vector<bool>(m));
        obst=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(grid[i][j]==-1)obst++;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(grid[i][j]==1){
            return solve(grid,i,j);
        }
        return -1;
    }
};