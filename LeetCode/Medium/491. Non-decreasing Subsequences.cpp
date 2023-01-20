class Solution {
    set<vector<int>> ans;
    vector<int> cur;
public:
    void GetA(vector<int>& nums, int v=-101,int i=0){
        if(i==nums.size()){
            if(cur.size()>1)ans.insert(cur);
            return;
        }
        if(nums[i]>=v){
            cur.push_back(nums[i]);
            GetA(nums,nums[i],i+1);
            cur.pop_back();
        }
        GetA(nums,v,i+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        GetA(nums);
        vector<vector<int>> res;
        for(const auto& v : ans)res.push_back(v);
        return res;
    }
};