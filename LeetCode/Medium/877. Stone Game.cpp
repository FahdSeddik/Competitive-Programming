class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(),ans=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int i=0;i<n;i++)dp[i][i]=piles[i],ans+=piles[i];
        for(int i=0;i<n-1;i++)dp[i][i+1]=max(piles[i],piles[i+1]);
        for(int len=2;len<n;len++){
            for(int i=0,j=len;j<n;j++,i++){
                dp[i][j]=max(piles[i]+min(dp[i+1][j-1],dp[i+2][j]),piles[j]+min(dp[i+1][j-1],dp[i][j-2]));
            }
        }
        return dp[0][n-1]>ans/2;
    }
};