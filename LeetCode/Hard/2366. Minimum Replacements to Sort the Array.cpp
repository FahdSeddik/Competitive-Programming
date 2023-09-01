class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0,last=nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            long long steps = (nums[i]-1)/last;
            last = nums[i]/(steps+1);
            ans+=steps;
        }
        return ans;
    }
};