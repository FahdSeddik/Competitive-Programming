class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        //bfs
        int n = board.size(),i=1;
        //linearize 
        vector<pair<int,int>> idx(n*n+1);
        vector<int> offsets(n);
        iota(offsets.begin(),offsets.end(),0);
        for(int r=n-1;r>=0;r--){
            for(auto c : offsets) idx[i++]={r,c};
            reverse(offsets.begin(),offsets.end());
        }
        queue<int> q;q.push(1);
        vector<int> depth(n*n+1,-1);
        depth[1]=0;
        while(!q.empty()){
            auto u = q.front();q.pop();
            for(i=u+1;i<=min(u+6,n*n);i++){
                auto [r,c]=idx[i];
                int next = board[r][c]!=-1 ? board[r][c] :i;
                if(depth[next]==-1)depth[next]=depth[u]+1,q.push(next);
            }
        }
        return depth[n*n];
    }
};