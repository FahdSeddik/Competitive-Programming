class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto i : arr){
            mp[i] = max(1,1+mp[i-difference]);
            ans = max(ans,mp[i]);
        }
        return ans;
    }
};