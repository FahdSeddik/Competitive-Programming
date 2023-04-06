class Solution {
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},ans,m,n;
public:
    void dfs(vector<vector<int>>& grid,int i,int j){
        grid[i][j]=1;
        for(int d=0;d<4;d++){
            int r=i+dx[d],c=j+dy[d];
            if(r<0 || c<0 || r>=m || c>=n || grid[r][c])continue;
            dfs(grid,r,c);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        ans=0,m=grid.size(),n=grid[0].size();
        for(int j=0;j<n;j++){
            if(!grid[0][j])dfs(grid,0,j);
            if(!grid[m-1][j])dfs(grid,m-1,j);
        }
        for(int i=0;i<m;i++){
            if(!grid[i][0])dfs(grid,i,0);
            if(!grid[i][n-1])dfs(grid,i,n-1);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j])ans++,dfs(grid,i,j);
            }
        }
        return ans;
    }
};