class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2(nums2.begin(),nums2.end());
        vector<vector<int>> ans(2);
        for(auto i : nums1){
            if(s1.count(i))continue;
            if(!s2.count(i))ans[0].push_back(i);
            s1.insert(i);
        }
        s2.clear();
        for(auto i : nums2){
            if(s2.count(i))continue;
            if(!s1.count(i))ans[1].push_back(i);
            s2.insert(i);
        }
        return ans;
    }
};