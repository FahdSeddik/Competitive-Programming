class Solution {
public:

    int bestTeamScore(vector<int>& scores, vector<int>& ages,int i=0) {
        int n=scores.size();
        if(n==1)return scores[0];
        vector<pair<int,int>> players(n);
        for(int i=0;i<n;i++)players[i]={ages[i],scores[i]};
        sort(players.begin(),players.end());
        int dp[1001],ans=INT_MIN;
        for(int i=0;i<n;i++){
            dp[i]=players[i].second;
            for(int j=0;j<i;j++)if(players[j].second<=players[i].second){
                dp[i] = max(dp[i],dp[j]+players[i].second);
            }
            ans = max(dp[i],ans);
        }
        return ans;
    }
};