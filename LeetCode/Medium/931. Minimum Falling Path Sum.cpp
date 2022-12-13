class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        //For each index store minimum falling path sum
        //for dp[i][j]=min(dp[i+1][j],dp[i+1][j+1],dp[i+1][j-1])+matrix[i][j]
        //traverse matrix from last layer and back
        for(int i=0;i<n;i++)dp[n-1][i]=matrix[n-1][i];
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<n-1;j++){
                int mn=dp[i+1][j];
                mn=min(mn,dp[i+1][j-1]);
                mn=min(mn,dp[i+1][j+1]);
                dp[i][j]=mn+matrix[i][j];
            }
            dp[i][0]=min(dp[i+1][1],dp[i+1][0])+matrix[i][0];
            dp[i][n-1]=min(dp[i+1][n-2],dp[i+1][n-1])+matrix[i][n-1];
        }
        return *min_element(dp[0],dp[0]+n);
    }
};