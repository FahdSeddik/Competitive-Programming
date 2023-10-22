class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size(),l=k,r=k,mx=nums[k],mn=nums[k];
        while(l>0 || r<n-1){
            if(l==0 || (r<n-1 && nums[r+1]>nums[l-1]))r++;
            else l--;
            mn=min(mn,min(nums[r],nums[l]));
            mx=max(mx,mn*(r-l+1));
        }
        return mx;
    }
};