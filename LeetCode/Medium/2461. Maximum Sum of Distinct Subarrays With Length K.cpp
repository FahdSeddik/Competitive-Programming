class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cnt=0;
        long long sum=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            sum+=nums[i];
            if(mp[nums[i]]==1)cnt++;
            if(i>=k){
                mp[nums[i-k]]--;
                sum-=nums[i-k];
                if(mp[nums[i-k]]==0)cnt--;
            }
            if(cnt==k)ans = max(ans,sum);
        }
        return ans;
    }
};