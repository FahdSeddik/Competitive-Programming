const int MOD = 1e9+7;
class Solution {
public:
    int numPermsDISequence(string s,int n=0) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        n = s.size();
        vector<int> dp(n+1,1),dp2(n);
        for (int i = 0; i < n; dp = dp2, i++) {
            if (s[i] == 'I')
                for (int j = 0, cur = 0; j < n - i; j++)
                    dp2[j] = cur = (cur + dp[j]) % MOD;
            else
                for (int j = n - i - 1, cur = 0; j >= 0; j--)
                    dp2[j] = cur = (cur + dp[j + 1]) % MOD;
        }
        return dp[0];
    }
};