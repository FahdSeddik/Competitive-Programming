class Solution {
    vector<int> dx{0,0,1,-1},dy{1,-1,0,0};
    unordered_set<string> ans;
    unordered_set<string> wrds;
public:
    void dfs(vector<vector<int>>& vs,vector<vector<bool>>& vis,vector<vector<char>>& board,int r,int c,int depth,string w=""){
        vis[r][c]=true;
        w+=board[r][c];
        if(depth>=9 && wrds.count(w) && !ans.count(w)){
            for (int i = 0; i < w.size(); i++) {
                vs[i][w[i] - 'a']--;
            }
            ans.insert(w);
            vis[r][c]=false;
            return;
        }else if(depth>=9){
            vis[r][c]=false;
            return;
        }
        if(wrds.count(w) && !ans.count(w)){
            for (int i = 0; i < w.size(); i++) {
                vs[i][w[i] - 'a']--;
            }
            ans.insert(w);
        }
        for(int i=0;i<4;i++){
            if(dx[i]+r<0 || dy[i]+c<0 || dx[i]+r>=board.size() || dy[i]+c>=board[0].size())continue;
            if(!vis[r+dx[i]][c+dy[i]] && vs[depth+1][board[r+dx[i]][c+dy[i]]-'a'])dfs(vs,vis,board,r+dx[i],c+dy[i],depth+1,w);
        }
        vis[r][c]=false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<int>> vs(10,vector<int>(26,0));
        for(int i=0;i<words.size();i++){
            wrds.insert(words[i]);
            for(int j=0;j<words[i].size();j++){
                vs[j][words[i][j]-'a']++;
            }
        }
        
        ans=unordered_set<string>();
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(!vis[i][j] && vs[0][board[i][j]-'a'])dfs(vs,vis,board,i,j,0);
            }
        }
        vector<string> res;
        for(auto s : ans){
            res.push_back(s);
        }
        return res;
    }
};