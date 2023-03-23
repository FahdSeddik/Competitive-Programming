class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        unordered_map<long long,long long> mp;
        long long len=0;
        for(auto i : nums){
            if(i==0)len++;
            else if(len)mp[len]++,len=0;
        }
        if(len)mp[len]++;
        long long ans=0;
        for(const auto& x : mp){
            ans+= x.second*(x.first*(x.first+1)/2);
        }
        return ans;
    }
};