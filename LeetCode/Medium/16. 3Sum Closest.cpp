class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int d=INT_MAX;
        int ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int s=nums[i]+nums[j]+nums[k];
                if(abs(s-target)<d)d=abs(s-target),ans=s;
                if(s>target)k--;
                else j++;
            }
        }
        return ans;
    }
};