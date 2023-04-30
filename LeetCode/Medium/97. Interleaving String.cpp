class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(),m=s2.size(),v=s3.size();
        if(n+m!=v)return false;
        bool dp[m+1];
        dp[0]=true;
        for(int j=1;j<=m;j++)dp[j]= s3[j-1]==s2[j-1]&&dp[j-1];
        for(int i=1;i<=n;i++){
            dp[0]&=s3[i-1]==s1[i-1];
            for(int j=1;j<=m;j++){
                dp[j]=(s3[i+j-1]==s1[i-1] && dp[j]) || (s3[i+j-1]==s2[j-1] && dp[j-1]);
            }
        }
        return dp[m];
    }
};