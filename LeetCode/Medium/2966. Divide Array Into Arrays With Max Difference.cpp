class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%3!=0)return {};
        vector<vector<int>> ans(n/3);
        sort(nums.begin(),nums.end());
        for(int i=0,j=0;i<n;i++){
            ans[j].push_back(nums[i]);
            if(ans[j].size()==3 && nums[i]-nums[i-2]>k)return {};
            if(ans[j].size()==3)j++;
        }
        return ans;
    }
};