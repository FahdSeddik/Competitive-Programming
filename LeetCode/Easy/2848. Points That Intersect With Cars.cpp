class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,mn=nums[0][0],mx=nums[0][1],n=nums.size();
        for(int i=1;i<n;i++){
            if(mx<nums[i][0]){
                ans+=mx-mn+1;
                mn=nums[i][0],mx=nums[i][1];
            }else{
                mn=min(nums[i][0],mn);
                mx=max(nums[i][1],mx);
            }
        }
        ans+=mx-mn+1;
        return ans;
    }
};