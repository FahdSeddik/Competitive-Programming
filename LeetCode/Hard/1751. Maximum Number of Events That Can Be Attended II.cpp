class Solution {
public:
    int solve(vector<vector<int>>& dp,vector<vector<int>>& events,int idx,int k,int end){
        if(idx==events.size())return 0;
        if(k==0)return 0;
        if(events[idx][0]<=end)return solve(dp,events,idx+1,k,end);
        if(dp[idx][k]!=-1)return dp[idx][k];
        return dp[idx][k]=max(events[idx][2]+solve(dp,events,idx+1,k-1,events[idx][1]),solve(dp,events,idx+1,k,end));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        // dp[i][k] --> dp[0][k] ans
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        return solve(dp,events,0,k,0);
    }
};