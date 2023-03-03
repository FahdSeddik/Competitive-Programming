class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        if(n<=3) return 0;
        int numones = accumulate(nums.begin(),nums.end(),0);
        if(numones==n-1 || numones==n)return 0;
        int sum=0;
        for(int i=0;i<numones;i++)sum+=nums[i];
        int ans=INT_MAX;
        sum-=nums[0];
        sum+=nums[numones];
        ans = min(ans,numones-sum);
        for(int i=numones+1;i!=numones && i<n;i=(i+1)%n){
            sum-=nums[(i-numones+n)%n];
            sum+=nums[i];
            ans = min(ans,numones-sum);
        }
        return ans;
    }
};