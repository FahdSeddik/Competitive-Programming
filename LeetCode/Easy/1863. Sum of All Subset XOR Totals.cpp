class Solution {
public:
    int subsetXOR(vector<int>& nums, int xorv=0, int i=0){
        if(i==nums.size())return xorv;
        int with = subsetXOR(nums, xorv^nums[i],i+1);
        int without = subsetXOR(nums, xorv, i+1);
        return with+without;
    }
    int subsetXORSum(vector<int>& nums) {
        return subsetXOR(nums);
    }
};