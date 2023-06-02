class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums.back()*k+(k*(k-1))/2;
    }
};