class Solution {
    int dr[8]={-1,-2,-2,-1,1,2,2,1},dc[8]={-2,-1,1,2,2,1,-1,-2};
    long long cnt=0,tot=0;
    double dp[30][30][105];
public:
    double dfs(int i,int j,int k, int n){
        if(i < 0 || j < 0 ||i >= n || j >= n) return 0;
        if(k == 0) return 1;
        if(dp[i][j][k] != 0) return dp[i][j][k];
        double res = 0;
        for(int l = 0;l < 8; ++l){
            res += dfs(i + dr[l],j + dc[l],k-1,n);
        }
        return dp[i][j][k] += (res/8.0);
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp,0,sizeof(dp));
        return dfs(row,column,k,n); 
    }
};