class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0]=1;
        int prod=1;
        for(int i=0;i<nums.size()-1;i++){
            prod*=nums[i];
            res[i+1]=prod;
        }
        prod=1;
        for(int i=nums.size()-1;i>=1;i--){
            prod*=nums[i];
            res[i-1]*=prod;
        }
        return res;
    }
};