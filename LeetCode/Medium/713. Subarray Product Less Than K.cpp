class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int ans=0,n=nums.size();
        for(int l=0,r=0,p=1;r<n;r++){
            p*=nums[r];
            while(p>=k)p/=nums[l++];
            ans+=r-l+1;
        }
        return ans;
    }
};