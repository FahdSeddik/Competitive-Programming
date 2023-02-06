class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n,int idx=0) {
        vector<int> ans(2*n);
        for(int i=0;i<n;i++)ans[idx++]=nums[i],ans[idx++]=nums[i+n];
        return ans;
    }
};