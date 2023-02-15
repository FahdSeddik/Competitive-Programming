class Solution {
    vector<vector<int>> ans;
    vector<int> cur;
    int n;
public:
    void solve(vector<int>& nums,int i=0){
        ans.push_back(cur);
        if(i==nums.size())return;
        for(;i<n;i++){
            cur.push_back(nums[i]);
            solve(nums,i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        solve(nums);
        return ans;
    }
};