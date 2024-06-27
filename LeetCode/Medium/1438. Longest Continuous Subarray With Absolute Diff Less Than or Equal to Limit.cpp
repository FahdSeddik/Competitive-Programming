class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m;
        int ans=1;
        for(int l=0,r=0;r<nums.size();r++){
            m.insert(nums[r]);
            int small=*m.begin(),large=*(--m.end());
            while(large-small>limit){
                m.erase(m.find(nums[l++]));
                small=*m.begin(),large=*(--m.end());
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};