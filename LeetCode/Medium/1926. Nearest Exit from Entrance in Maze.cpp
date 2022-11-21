class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> dx{0,0,1,-1},dy{1,-1,0,0};
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        int depth=0,size=1;
        vector<vector<bool>> vis(maze.size(),vector<bool>(maze[0].size(),false));
        for(;!q.empty();++depth,size=q.size()){
            while(size--){
                pair<int,int> cur = q.front();q.pop();
                if(vis[cur.first][cur.second])continue;
                vis[cur.first][cur.second]=true;
                for(int i=0;i<4;i++){
                    int r = cur.first + dy[i];
                    int c = cur.second + dx[i];
                    if(r<0 || r>=maze.size() || c<0 || c>=maze[0].size())continue;
                    if(vis[r][c] || maze[r][c]=='+')continue;
                    if(r==0 || r==maze.size()-1 || c==0 || c==maze[0].size()-1)return depth+1;
                    q.push({r,c});
                }
            }
        }
        return -1;
    }
};