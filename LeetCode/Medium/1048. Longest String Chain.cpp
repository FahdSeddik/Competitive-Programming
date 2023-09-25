class Solution {
public:

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[&](string& a,string& b){
            return a.size()<b.size();
        });
        unordered_map<string,int> dp;
        int ans=1;
        for(auto& word:words){
            dp[word]=1;
            for(int i=0;i<word.size();i++){
                string temp = word.substr(0,i)+word.substr(i+1);
                if(dp.count(temp))dp[word]=max(dp[word],dp[temp]+1);
            }
            ans=max(ans,dp[word]);
        }
        return ans;
    }
};