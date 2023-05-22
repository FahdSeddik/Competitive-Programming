class Solution {
public:
    vector<int> dx = {1,-1,0,0},dy={0,0,1,-1};
    int n;
    void dfs(int i,int j,vector<vector<int>>& grid,queue<pair<int,int>>&q){
        grid[i][j]=2;
        q.push({i,j});
        for(int d = 0;d<4;d++){
            int r = i+dx[d],c=j+dy[d];
            if(r<0 || c<0 || r>=n || c>=n)continue;
            if(grid[r][c]==0 ||grid[r][c]==2)continue;
            dfs(r,c,grid,q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            bool br=false;
            for(int j=0;j<n;j++)if(grid[i][j]){
                    br=true,dfs(i,j,grid,q);
                    break;
            }
            if(br)break;
        }
        int size = q.size(),depth=0;
        for(;!q.empty();size=q.size(),depth++){
            while(size--){
                auto x  = q.front();q.pop();
                for(int d = 0;d<4;d++){
                    int r = x.first+dx[d],c=x.second+dy[d];
                    if(r<0 || c<0 || r>=n || c>=n)continue;
                    if(grid[r][c]==1)return depth;
                    if(grid[r][c]==0)q.push({r,c}),grid[r][c]=2;
                }
            }
        }
        return 0;
    }
};