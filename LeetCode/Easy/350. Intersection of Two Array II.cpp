class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size())return intersect(nums2,nums1);
        vector<int> n(1001);
        vector<int> ans;
        for(auto i : nums1){
            n[i]++;
        }
        for(auto i: nums2){
            if(n[i]-->0)ans.push_back(i);
        }
        return ans;
    }
};