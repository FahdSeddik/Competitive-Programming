const int MOD = 1e9+7;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int pows[nums.size()];
        pows[0]=1;
        for(int i=1;i<nums.size();i++)pows[i] = (pows[i-1] * 2)%MOD;
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1,ans=0;
        while(l<=r){
            if(nums[l]+nums[r]>target)r--;
            else{
                ans = (ans+pows[r-l++])%MOD;
            }
        }
        return ans;
    }
};