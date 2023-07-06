class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int cursum=0;
        int ans=INT_MAX;
        int l=0,r=0;
        for(auto v : nums){
            cursum+=v,r++;
            while(cursum>=target && l<r){
                ans=min(ans,r-l);
                cursum-=nums[l],l++;
            }
        }
        return ans==INT_MAX ? 0:ans;
    }
};