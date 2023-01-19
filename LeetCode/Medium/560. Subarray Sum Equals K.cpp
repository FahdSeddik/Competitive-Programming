class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //sum -> count
        unordered_map<int,int> mp;
        int cursum=0,ans=0;mp[cursum]=1;
        for(const auto& v : nums){
            cursum+=v;
            if(mp.find(cursum-k) != mp.end()){
                ans+=mp[cursum-k];
            }
            mp[cursum]++;
        }
        return ans;
    }
};