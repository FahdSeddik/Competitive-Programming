class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unsigned long long ans = 0;
        for(int v : nums)ans+=v;
        for(int i=nums.size()-1;i>=2;i--){
            if(ans-nums[i]>nums[i])return ans;
            ans-=nums[i];
        }
        return -1;
    }
};