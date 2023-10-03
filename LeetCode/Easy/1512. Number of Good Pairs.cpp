class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto v : nums)ans+=mp[v],mp[v]++;
        return ans;
    }
};