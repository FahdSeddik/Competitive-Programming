class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==2)return nums[0]==nums[1];
        if(n==3)return (nums[0]==nums[1] && nums[0]==nums[2]) || (nums[0]+1==nums[1] && nums[1]+1==nums[2]);
        vector<bool> dp(n+1);
        dp[0]= true;
        dp[1]=nums[0]==nums[1];
        dp[2]=(nums[0]==nums[1] && nums[0]==nums[2]) || (nums[0]+1==nums[1] && nums[1]+1==nums[2]);
        dp[3]=dp[1] && nums[2]==nums[3];
        for(int i=4;i<n;i++){
            dp[i]=dp[i-2] && nums[i-1]==nums[i];
            dp[i]=dp[i] || dp[i-3] && nums[i-2]==nums[i-1] && nums[i-1]==nums[i];
            dp[i]=dp[i] || dp[i-3] && nums[i-2]+1==nums[i-1] && nums[i-1]+1==nums[i];
        }
        return dp[n-1];
    }
};