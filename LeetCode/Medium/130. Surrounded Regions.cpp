class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(),n=board[0].size();
        int dx[]={0,0,1,-1,},dy[]={1,-1,0,0};
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n));
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')q.push({0,i}),vis[0][i]=true;
            if(board[m-1][i]=='O')q.push({m-1,i}),vis[m-1][i]=true;
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')q.push({i,0}),vis[i][0]=true;
            if(board[i][n-1]=='O')q.push({i,n-1}),vis[i][n-1]=true;
        }
        int size=q.size();
        for(;!q.empty();size=q.size()){
            while(size--){
                auto [i,j] = q.front();q.pop();
                for(int d=0;d<4;d++){
                    int r =i+dx[d],c=j+dy[d];
                    if(r<0 || c<0 || r>=m || c>=n)continue;
                    if(board[r][c]=='X' || vis[r][c])continue;
                    vis[r][c]=true;
                    q.push({r,c});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)if(!vis[i][j])board[i][j]='X';
        }
    }
};