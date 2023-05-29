class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if(n==1)return stoneValue[0]>0 ? "Alice":stoneValue[0]==0 ? "Tie":"Bob";
        int tot=0;
        vector<int> dp(n+7);
        dp[n-1]=stoneValue[n-1];
        dp[n-2]=max(stoneValue[n-2],stoneValue[n-1]+stoneValue[n-2]);
        tot+=stoneValue[n-1]+stoneValue[n-2];
        for(int i=n-3;i>=0;i--){
            tot+=stoneValue[i];
            dp[i]=stoneValue[i]+min(dp[i+2],min(dp[i+3],dp[i+4]));
            dp[i]=max(dp[i],stoneValue[i]+stoneValue[i+1]+min(dp[i+3],min(dp[i+4],dp[i+5])));
            dp[i]=max(dp[i],stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]+min(dp[i+4],min(dp[i+5],dp[i+6])));
        }
        return tot-dp[0]==dp[0] ? "Tie":tot-dp[0]>dp[0] ? "Bob":"Alice";
    }
};