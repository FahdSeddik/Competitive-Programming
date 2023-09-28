class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        vector<int> ans(nums.size());
        for(auto v : nums)if(v%2==0)ans[l++]=v;else ans[r--]=v;
        return ans;
    }
};