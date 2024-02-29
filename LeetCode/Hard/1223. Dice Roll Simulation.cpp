class Solution {
    vector<vector<vector<int>>> dp;
    const int MOD = 1e9+7;
public:
    int solve(vector<int>& rollMax, int rolls, int last, int uses){
        if(rolls<=0)return 1;
        if(dp[rolls][last][uses]!=-1)return dp[rolls][last][uses];
        int ans=0;
        for(int i=1;i<=6;i++){
            if(last!=i || uses+1<=rollMax[i-1]){
                ans=(ans+solve(rollMax,rolls-1,i,last==i ? uses+1:1))%MOD;
            }
        }
        return dp[rolls][last][uses]=ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        dp.resize(n+1,vector<vector<int>>(7,vector<int>(16,-1)));
        return solve(rollMax,n,0,0);
    }
};

/*


*/