class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid=0;
        while(mid<=r){
            if(nums[mid]==0){
                swap(nums[mid],nums[l]);
                l++,mid++;
            }else if(nums[mid]==2){
                swap(nums[mid],nums[r]);
                r--;
            }else mid++;
        }
    }
};