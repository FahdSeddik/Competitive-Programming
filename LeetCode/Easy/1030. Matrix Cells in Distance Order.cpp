static const int fast_io = [](){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}();

class Solution {
    vector<int> dx{1,-1,0,0},dy{0,0,1,-1};
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans(rows*cols),vis(rows,vector<int>(cols));
        queue<pair<int,int>> q;
        q.push({rCenter,cCenter});
        int i=0;
        while(!q.empty()){
            auto x = q.front();q.pop();
            if(vis[x.first][x.second])continue;
            vis[x.first][x.second]=1;
            ans[i++]={x.first,x.second};
            for(int d=0;d<4;d++){
                int r=x.first+dx[d],c=x.second+dy[d];
                if(r<0 || c<0 || r>=rows || c>=cols || vis[r][c])continue;
                q.push({r,c});
            }
        }
        return ans;
    }
};