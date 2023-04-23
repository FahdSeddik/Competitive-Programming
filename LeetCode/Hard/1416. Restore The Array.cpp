const int MOD = 1e9+7;
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            long long num=0,tot=0;
            for(int j=i;j<n;j++){
                num =(num*10)+ s[j]-'0';
                if(num<1 || num>k)break;
                tot=(tot+dp[j+1])%MOD;
            }
            dp[i]=tot;
        }
        return dp[0];
    }
};