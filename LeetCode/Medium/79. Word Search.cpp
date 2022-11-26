class Solution {
    vector<int> dx{0,0,1,-1},dy{1,-1,0,0};
public:
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& vis,string& word,int i,int j,int index){
        if(index==word.size())return true;
        vis[i][j]=true;
        for(int ch=0;ch<4;ch++){
            int r=i+dx[ch],c=j+dy[ch];
            if(r<0 || c<0 || r>=board.size() || c>=board[0].size())continue;
            if(!vis[r][c] && board[r][c]==word[index] && dfs(board,vis,word,r,c,index+1))return true;
        }
        vis[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && !vis[i][j]){
                    if(dfs(board,vis,word,i,j,1))return true;
                }
            }
        }
        return false;
    }
};