class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        int dp[2][2];
        int ans=0;
        dp[0][0]=nums[0],dp[0][1]=0;
        for(int i=1;i<n-1;i++){
            dp[i%2][0]=dp[(i-1)%2][1]+nums[i];
            dp[i%2][1]=max(dp[(i-1)%2][0],dp[(i-1)%2][1]);
        }
        ans=max(dp[(n-2)%2][0],dp[(n-2)%2][1]);
        dp[(n-1)%2][0]=nums[n-1],dp[(n-1)%2][1]=0;
        for(int i=n-2;i>=1;i--){
            dp[i%2][0]=dp[(i+1)%2][1]+nums[i];
            dp[i%2][1]=max(dp[(i+1)%2][0],dp[(i+1)%2][1]);
        }
        return max(ans,max(dp[1][0],dp[1][1]));
    }
};