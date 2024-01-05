class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int v : nums)mp[v]++;
        int ans=0;
        for(auto& x : mp){
            if(x.second==1)return -1;
            ans+=x.second%3==0?x.second/3:x.second/3+1;
        }
        return ans;
    }
};