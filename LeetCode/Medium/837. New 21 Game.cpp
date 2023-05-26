class Solution {
public:
    double new21Game(int n, int k, int pts) {
        if(n>=k+pts || k == 0) return 1.0;
        vector<double>dp(n+1,0);
        double pSum =1.0;
        double res= 0.0;
        dp[0] = 1.0;
        for(int i=1;i<=n;i++){
            dp[i] = pSum/pts;
            if(i<k) pSum += dp[i];
            else res += dp[i];
            if(i-pts >=0) pSum -= dp[i-pts];
        }
        return res;
    }
};