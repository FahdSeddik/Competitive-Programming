class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.')continue;
                for(char k='1';k<='9';k++){
                    if(can(board,i,j,k)){
                        board[i][j]=k;
                        if(solve(board))return true;
                        else board[i][j]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    bool can(vector<vector<char>>& board,int i,int j,char n){
        //vert and hor
        for(int k=0;k<board.size();k++){
            if(board[k][j]==n || board[i][k]==n)return false;
        }
        //get square
        int r=(i/3)*3,c=(j/3)*3;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(board[r+k][c+l]==n)return false;
            }
        }
        return true;
    }
};