int dp[101][101];
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        sort(cuts.begin(), cuts.end());
        memset(dp,0,sizeof(dp));
        for(int i=m-1;i>=0;i--) {
            for(int j=i+1;j<=m;j++) {
                int cost=(j==m ? n:cuts[j])-(i==0 ? 0:cuts[i-1]);
                dp[i][j]=cost+dp[i+1][j];
                for(int k=i+1; k<j; ++k) {
                    dp[i][j]=min(dp[i][j],cost+dp[i][k]+dp[k+1][j]);
                }
            }
        }
        return dp[0][m];
    }
};