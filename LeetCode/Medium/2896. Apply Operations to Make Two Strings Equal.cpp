class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> idx;
        for(int i=0;i<s1.size();i++)if(s1[i]!=s2[i])idx.push_back(i);
        int n = idx.size();
        if(n%2==1)return -1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        function<int(int,int)> solve = [&](int i,int j){
            if(i==j)return 0;
            if(dp[i][j]!=-1)return dp[i][j];
            int res=500*500;
            for(int k=i+1;k<j;k+=2){
                res=min(res,min(x, idx[k]-idx[i])+solve(i+1,k)+solve(k+1,j));
            }
            return dp[i][j]=res;
        };
        return solve(0,n);
    }
};