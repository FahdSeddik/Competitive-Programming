class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n));
        int tot=0;
        for(int i=0;i<n;i++)dp[i][i]=nums[i],tot+=nums[i];
        for(int i=0;i<n-1;i++)dp[i][i+1]=max(dp[i][i],dp[i+1][i+1]);
        for(int len=3;len<=n;len++){
            for(int l=0,r=len-1;r<n;r++,l++){
                dp[l][r]=max(dp[l][l]+min(dp[l+1][r-1],dp[l+2][r]),dp[r][r]+min(dp[l][r-2],dp[l+1][r-1]));
            }
        }
        return dp[0][n-1]>=(tot-dp[0][n-1]);
    }
};