class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int ans=-1e9,sum=-1e9;
        for(int i=0;i<nums.size();i++){
            sum = max(nums[i],nums[i]+sum);
            ans = max(ans,sum);
        }
        return ans;
    }
};