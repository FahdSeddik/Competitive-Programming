class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s;
        int ans = -1;
        for(int v : nums){
            if(s.count(-v))ans=max(ans,abs(v));
            s.insert(v);
        }
        return ans;
    }
};