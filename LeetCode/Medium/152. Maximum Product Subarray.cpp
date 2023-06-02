class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref=1,suf=1,maxi=-1e9,n=nums.size();
        for(int i=0;i<n;i++){
            if(pref==0) pref=1;
            if(suf==0) suf=1;
            pref*=nums[i];
            suf*=nums[n-1-i];
            maxi=max(maxi,max(pref,suf));           
        }
        return maxi;
    }
};