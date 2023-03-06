class Solution {
    int dp[6][51];
    int solve(int i, int n, int k){
        if(k==0 || i==n)return k==0;
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        return dp[i][k]=solve(i,n,k-1)+solve(i+1,n, k);
    }
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int countVowelStrings(int k) {
        memset(dp,-1, sizeof(dp));
        return  solve(0, 5, k);
    }
};