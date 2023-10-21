static const int fast_io = [](){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}();
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0,alive=0;j<m;j++,alive=0){
                for(int w=max(i-1,0);w<min(i+2,n);w++)
                for(int z=max(j-1,0);z<min(j+2,m);z++)
                alive+=board[w][z]&1;
                if(alive==3 || alive-board[i][j]==3)board[i][j]|=2;
            }
        }
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)
        board[i][j]>>=1;
    }
};