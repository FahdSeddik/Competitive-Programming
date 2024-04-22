class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(),nums.end()),n=nums.size();
        long long ans=0;
        for(int i=0,l=0;i<n;i++){
            if(nums[i]==mx)k--;
            while(!k)if(nums[l++]==mx)k++;
            ans+=l;
        }
        return ans;
    }
};