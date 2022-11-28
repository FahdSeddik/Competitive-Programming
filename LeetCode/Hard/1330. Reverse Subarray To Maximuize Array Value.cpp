class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n=nums.size(),mn=INT_MAX,mx=INT_MIN,ans=0,candid=0;
        for(int i=0;i<n-1;i++){
            int a=nums[i],b=nums[i+1];
            ans+=abs(a-b);
            candid=max(candid,abs(nums[0]-b)-abs(a-b));
            candid=max(candid,abs(nums[n-1]-a)-abs(a-b));
            mn = min(mn,max(a,b));
            mx = max(mx,min(a,b));
        }
        return ans+ max(candid,(mx-mn)*2);
    }
};