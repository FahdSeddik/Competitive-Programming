class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        if(tokens.empty() || power<tokens[0])return 0;
        int ans=0,n=tokens.size(),score=0;
        for(int l=0,r=n-1;l<=r;){
           if(power>=tokens[l])power-=tokens[l++],++score;
           else power+=tokens[r--],--score;
           ans=max(ans,score);
        }
        return ans;
    }
};