class Solution {
    int m,n,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j){
        vis[i][j]=true;
        for(int d=0;d<4;d++){
            int r=i+dx[d],c=j+dy[d];
            if(r<0 || c<0 || r>=m || c>=n || vis[r][c])continue;
            if(grid[r][c]=='0')continue;
            dfs(grid,vis,r,c);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1')ans++,dfs(grid,vis,i,j);
            }
        }
        return ans;
    }
};