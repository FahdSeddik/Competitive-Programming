class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int bad_idx=-1,l_idx=-1,r_idx=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxK || nums[i]<minK)bad_idx=i;
            if(nums[i]==minK)l_idx=i;
            if(nums[i]==maxK)r_idx=i;
            ans+= max(0,min(l_idx,r_idx)-bad_idx);
        }
        return ans;
    }
};