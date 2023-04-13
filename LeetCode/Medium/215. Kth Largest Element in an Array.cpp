class Solution {
public:
    int quickselect(vector<int>&nums, int l, int r, int k){
        if(l>=r) return nums[l];
        int pivot=nums[l+r>>1];
        int i=l-1,j=r+1;
        while(i<j){
            while(nums[++i]>pivot);
            while(nums[--j]<pivot);
            if(i<j)swap(nums[i],nums[j]);
        }
        int sl=j-l+1;
        if(k<=sl) return quickselect(nums,l,j,k);
        return quickselect(nums,j+1,r,k-sl);
    }
    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        return quickselect(nums, 0, nums.size()-1, k);        
    }
};