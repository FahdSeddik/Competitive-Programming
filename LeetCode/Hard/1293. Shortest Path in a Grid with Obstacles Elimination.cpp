class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        if(grid.size()==1 && grid[0].size()==1)return 0;
        vector<int> dx{0,0,1,-1},dy{1,-1,0,0};
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},k});
        int depth=0,size=1;
        vector<vector<vector<bool>>> vis(grid.size(),vector<vector<bool>>(grid[0].size(),vector<bool>(k+1,false)));
        for(;!q.empty();++depth,size=q.size()){
            while(size--){
                auto v = q.front();q.pop();
                pair<int,int> cur = v.first;
                int left = v.second;
                if(vis[cur.first][cur.second][left])continue;
                vis[cur.first][cur.second][left]=true;
                for(int i=0;i<4;i++){
                    int y = cur.first + dy[i];
                    int x = cur.second + dx[i];
                    if(y<0 || x<0 || x>=grid[0].size() || y>=grid.size())continue;
                    if(y==grid.size()-1 && x==grid[0].size()-1)return depth+1;
                    if(grid[y][x] && !left)continue;
                    if(grid[y][x]){
                        if(vis[y][x][left-1])continue;
                        q.push({{y,x},left-1});
                    }else {
                        if(vis[y][x][left])continue;
                        q.push({{y,x},left});
                    }
                }
            }
        }
        return -1;
    }
};