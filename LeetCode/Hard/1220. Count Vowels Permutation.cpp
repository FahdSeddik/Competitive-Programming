class Solution {
public:
    int countVowelPermutation(int n) {
        int dp[2][5]={0},MOD=1e9+7;
        dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=dp[0][4]=1;
        for(int i=1;i<n;i++){
            int cur=i%2,prev=(i-1)%2;
            dp[cur][0]=((dp[prev][1]+dp[prev][2])%MOD+dp[prev][4])%MOD;
            dp[cur][1]=(dp[prev][0]+dp[prev][2])%MOD;
            dp[cur][2]=(dp[prev][3]+dp[prev][1])%MOD;
            dp[cur][3]=dp[prev][2]%MOD;
            dp[cur][4]=(dp[prev][2]+dp[prev][3])%MOD;
        }
        int ans=0;
        for(int i=0;i<5;i++)ans=(ans+dp[(n-1)%2][i])%MOD;
        return ans;
    }
};

/*
a-0 e-1 i-2 o-3 u-4
dp[i][0] = dp[i-1][1]+dp[i-1][2]+dp[i-1][4]
dp[i][1] = dp[i-1][0]+dp[i-1][2]
dp[i][2] = dp[i-1][1]+dp[i-1][3]
dp[i][3] = dp[i-1][2]
dp[i][4] = dp[i-1][2]+dp[i-1][3]
*/