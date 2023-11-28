class Solution {
public:
    int knightDialer(int n) {
        if(n==1)return 10;
        int dp[2][10],MOD=1e9+7;
        memset(dp,0,sizeof(dp));
        dp[0][0]=dp[0][1]=dp[0][2]=dp[0][6]=dp[0][7]=dp[0][8]=dp[0][9]=2;
        dp[0][3]=dp[0][5]=3;
        for(int i=1;i<n;i++){
            dp[i%2][0]=(dp[(i-1)%2][7]+dp[(i-1)%2][5])%MOD;
            dp[i%2][1]=(dp[(i-1)%2][6]+dp[(i-1)%2][8])%MOD;
            dp[i%2][2]=(dp[(i-1)%2][3]+dp[(i-1)%2][7])%MOD;
            dp[i%2][3]=((dp[(i-1)%2][9]+dp[(i-1)%2][8])%MOD+dp[(i-1)%2][2])%MOD;
            dp[i%2][5]=((dp[(i-1)%2][9]+dp[(i-1)%2][6])%MOD+dp[(i-1)%2][0])%MOD;
            dp[i%2][6]=(dp[(i-1)%2][1]+dp[(i-1)%2][5])%MOD;
            dp[i%2][7]=(dp[(i-1)%2][0]+dp[(i-1)%2][2])%MOD;
            dp[i%2][8]=(dp[(i-1)%2][1]+dp[(i-1)%2][3])%MOD;
            dp[i%2][9]=(dp[(i-1)%2][3]+dp[(i-1)%2][5])%MOD;
        }
        int ans=0;
        for(int i=0;i<10;i++)ans=(ans+dp[n%2][i])%MOD;
        return ans;
    }
};