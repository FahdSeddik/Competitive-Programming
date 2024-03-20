class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        if(goal<0) return 0;
        int i=0,n=nums.size(),count=0,sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(sum>goal){
                sum-=nums[i++];
            }
            count+=(j-i+1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};