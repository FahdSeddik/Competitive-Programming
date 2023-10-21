class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp=nums;
        deque<int> q;
        for(int i=0;i<n;i++){
            if(!q.empty() && i-q.front()>k)q.pop_front();
            dp[i]+=q.empty() ? 0:dp[q.front()];
            while(!q.empty() && dp[q.back()]<dp[i])q.pop_back();
            if(dp[i]>0)q.push_back(i);
        }
        return *max_element(dp.begin(),dp.end());
    }
};