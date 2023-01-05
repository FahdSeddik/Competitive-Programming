class Solution {
    vector<vector<string>> ans;
    unordered_set<int> col,posDiag,negDiag;
    int n;
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        vector<string> board(n,string(n,'.'));
        solve(board,0);
        return ans;
    }
    void solve(vector<string>& board, int r){
        if(r==n)return ans.push_back(board);
        for(int c=0;c<n;c++){
            if(col.count(c) || posDiag.count(r+c) || negDiag.count(r-c)){
                continue;
            }
            col.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);
            board[r][c]='Q';
            solve(board,r+1);
            col.erase(col.find(c));
            posDiag.erase(posDiag.find(r+c));
            negDiag.erase(negDiag.find(r-c));
            board[r][c]='.';
        }
    }
};