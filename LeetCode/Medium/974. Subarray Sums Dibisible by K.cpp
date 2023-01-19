class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0,cursum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(const auto& v : nums){
            cursum = ((cursum+v)%k+k)%k;
            ans+=mp[cursum];
            mp[cursum]++;
        }
        return ans;
    }
};