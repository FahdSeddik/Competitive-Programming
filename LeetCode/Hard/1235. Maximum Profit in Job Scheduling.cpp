class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = (int)startTime.size();
        vector<pair<pair<int,int>,int>> stend(n);
        for(int i=0;i<n;i++)stend[i].first.first=startTime[i],stend[i].first.second=endTime[i],stend[i].second=profit[i];
        sort(stend.begin(),stend.end(),[&](auto &j1, auto &j2){
            if(j1.first.second == j2.first.second) 
                return j1.second > j2.second;
            return j1.first.second < j2.first.second;
        });
        vector<int> dp(n+1,0);
        dp[1] = stend[0].second;
        for(int i = 2; i <= n; i++) {
            int l = 0, r = i - 2, j = 0;

            while(l <= r) {
                int mid = l + (r - l) / 2;

                if(stend[mid].first.second <= stend[i - 1].first.first) {
                    j = mid + 1;
                    l = mid + 1;
                }
                else { r = mid - 1; }
            }
            dp[i] = max(dp[i - 1], stend[i - 1].second + dp[j]);
        }
        return dp[n];
    }
};