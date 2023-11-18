class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0,j=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(1LL*(i-j+1)*nums[i]-sum>k)sum-=nums[j++];
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};