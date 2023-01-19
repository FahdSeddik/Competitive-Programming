class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long n = nums.size(),rem=0,cursum=0,ans=n;
        for(const auto& v : nums)rem = (rem+v)%p;
        unordered_map<long long,long long> mp;mp[0]=-1;
        for(int i=0;i<n;i++){
            cursum = (cursum+nums[i])%p;
            mp[cursum]=i;
            if(mp.find((cursum-rem+p)%p)!=mp.end())ans = min(ans,i - mp[(cursum-rem+p)%p]);
        }
        return ans<n ? ans : -1;
    }
};