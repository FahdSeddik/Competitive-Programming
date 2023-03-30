class Solution {
    int n;
public:
    int solve(vector<int>& days,vector<int>& cost,vector<int>& dp,int i){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int oned = cost[0]+solve(days,cost,dp,i+1);
        int j=i;
        while(j<n && days[j]<days[i]+7)j++;
        int twod = cost[1]+solve(days,cost,dp,j);
        j=i;
        while(j<n && days[j]<days[i]+30)j++;
        int threed = cost[2]+solve(days,cost,dp,j);
        return dp[i]=min(oned,min(twod,threed));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        vector<int> dp(n,-1);
        return solve(days,costs,dp,0);
    }
};