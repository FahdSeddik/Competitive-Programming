class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        int dp[2][n+1];
        dp[0][0]=dp[1][0]=0;
        for(int i=0;i<=n;i++)dp[0][i]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[j-1]==text2[i-1])dp[i%2][j]=1+dp[(i-1)%2][j-1];
                else dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
            }
        }
        return dp[m%2][n];
    }
};