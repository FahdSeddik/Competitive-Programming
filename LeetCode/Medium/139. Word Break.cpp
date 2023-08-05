class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0)return false;
        int n = s.size();
        bool dp[301];
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        unordered_set<string> wd(wordDict.begin(),wordDict.end());
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    string seg = s.substr(j,i-j);
                    if(wd.count(seg)){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};