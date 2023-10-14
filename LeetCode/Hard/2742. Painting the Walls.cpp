class Solution {
    int n;
public:
    int solve(vector<vector<int>>& dp,vector<int>& cost,vector<int>& time,int i=0,int busy=0){
        if(busy>=n)return 0;
        if(i==n)return 1e9;
        if(dp[i][busy]!=-1)return dp[i][busy];
        int one = solve(dp,cost,time,i+1,busy+1+time[i])+cost[i];
        int two = solve(dp,cost,time,i+1,busy);
        return dp[i][busy]=min(one,two);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(dp,cost,time);
    }
};