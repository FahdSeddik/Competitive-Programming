class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j])q.push({i,j});
            }
        }
        int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
        int size=q.size(),depth=-1;
        if(size==n*n || !size)return -1;
        for(;!q.empty();depth++,size=q.size()){
            while(size--){
                const auto [i,j]= q.front();q.pop();
                for(int d=0;d<4;d++){
                    int x=i+dx[d],y=j+dy[d];
                    if(x>=0 && x<n && y>=0 && y<n && !vis[x][y]){
                        vis[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
        }
        return depth;
    }
};