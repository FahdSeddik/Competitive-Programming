class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        while(l<r-1){
            int mid = (l+r)/2;
            if(nums[l]>nums[mid])r=mid;
            else l=mid;
        }
        return min(nums[0],nums[r]);
    }
};