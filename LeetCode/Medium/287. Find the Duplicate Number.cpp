class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int v : nums){
            int a=abs(v);
            if(nums[a-1]<0)return a;
            nums[a-1]=-nums[a-1];
        }
        return -1;
    }
};