class Solution {
public:
    int rev(int x){
        int res=0;
        while(x){
            res*=10;
            res+=x%10;
            x/=10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0,MOD=1e9+7;
        for(auto v : nums){
            int diff = v-rev(v);
            ans=(ans+mp[diff])%MOD;
            mp[diff]++;
        }
        return ans;
    }
};