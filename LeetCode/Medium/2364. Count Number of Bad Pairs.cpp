class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // nums[i] - i -> count
        unordered_map<long long,long long> mp;
        long long ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]-i)!=mp.end())ans+=mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        return n*(n-1)/2-ans;
    }
};