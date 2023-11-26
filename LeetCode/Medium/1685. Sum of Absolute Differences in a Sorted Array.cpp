class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> forward(n+1),backward(n+1);
        partial_sum(nums.begin(),nums.end(),forward.begin()+1);
        partial_sum(nums.rbegin(),nums.rend(),backward.rbegin()+1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=1LL*nums[i]*i-forward[i]-1LL*nums[i]*(n-i-1)+backward[i+1];
        }
        return ans;
    }
};