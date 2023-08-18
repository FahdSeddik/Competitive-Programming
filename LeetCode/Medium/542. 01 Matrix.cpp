class Solution {
    vector<int> dx={1,-1,0,0},dy={0,0,1,-1};
    int m,n;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size(),n=mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX)),vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)dp[i][j]=0,q.push({i,j});
            }
        }
        int size=1;
        for(;!q.empty();size=q.size()){
            while(size--){
                auto x = q.front();q.pop();
                int i=x.first,j=x.second;
                if(vis[i][j])continue;
                vis[i][j]=true;
                for(int d=0;d<4;d++){
                    int r=dx[d]+i,c=dy[d]+j;
                    if(r>=m || c>=n || r<0 || c<0 || mat[r][c]==0)continue;
                    dp[r][c]=min(dp[r][c],1+dp[i][j]);
                    q.push({r,c});
                }
            }
        }
        return dp;
    }
};