const int MOD = 1e9+7;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n=target.size(),m=words[0].size();
        vector<vector<int>> freq(26,vector<int>(m));
        for(auto w : words)
            for(int i=0;i<w.size();i++)freq[w[i]-'a'][i]++;
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                dp[j+1] = (dp[j+1]+(long long)dp[j]*freq[target[j]-'a'][i])%MOD;
            }
        }
        return dp[n];
    }
};

/*

    0   1   2   3
a   1   1   0   2
b   1   1   1   1
c   1   1   2   0

aba
1*1*0+1*1*2
+
1*1*2
+
1*1*2


*/