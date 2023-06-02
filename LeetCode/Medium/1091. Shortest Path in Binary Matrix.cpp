class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        int n = grid.size();
        if(n==1 && grid[0][0]==0)return 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=3;
        vector<int> dx = {1,-1,0,0,1,1,-1,-1},dy={0,0,1,-1,1,-1,1,-1};
        int size=1,depth=0;
        for(;!q.empty();size=q.size(),depth++){
            while(size--){
                auto x = q.front();q.pop();
                for(int d=0;d<8;d++){
                    int r = x.first+dx[d],c=x.second+dy[d];
                    if(r<0 || c<0 || r>=n || c>=n)continue;
                    if(grid[r][c]==0){
                        if(r==n-1 && c==n-1)return depth+2;
                        grid[r][c]=3,q.push({r,c});
                    }
                }
            }
        }
        return -1;
    }
};