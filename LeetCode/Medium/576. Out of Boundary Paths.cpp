const int MOD = 1e9 + 7;
class Solution {
    int m,n,dp[51][51][51];
    vector<pair<int,int>> dxdy={{1,0},{-1,0},{0,-1},{0,1}};
public:
    int solve(int i,int j,int moves){
        if(i<0 || i>=m || j<0 || j>=n)return 1;
        if(moves==0)return 0;
        if(dp[i][j][moves]!=-1)return dp[i][j][moves];
        long long ans = 0;
        for(auto& [dx,dy] : dxdy){
            int r = i+dx,c=j+dy;
            ans=(ans+solve(r,c,moves-1))%MOD;
        }
        return dp[i][j][moves]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m=m,this->n=n;
        memset(dp,-1,sizeof(dp));
        return solve(startRow,startColumn,maxMove);
    }
};