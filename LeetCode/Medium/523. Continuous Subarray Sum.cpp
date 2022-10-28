class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int cursum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            if(cursum % k == 0 && i > 0)return true;
            if(mp[cursum % k] && (i+1 - mp[cursum % k] >= 2))return true;
            if(mp[cursum % k] == 0)mp[cursum % k] = i+1;
        }
        return false;
    }
};