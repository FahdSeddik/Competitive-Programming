class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int>dp(n);
        for(auto v : nums)dp[v]+=v;
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i]+dp[i-2],dp[i-1]);
        }
        return dp.back();
    }
};