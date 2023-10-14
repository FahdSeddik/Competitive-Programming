class Solution {
    unordered_map<char,int> lcnt;
    vector<vector<int>> dp;
public:
    int solve(vector<string>& words,vector<int>& score,int i,int state){
        if(i==words.size())return 0;
        if(dp[i][state]!=-1)return dp[i][state];
        state|=1<<i;
        unordered_map<char,int> temp;
        for(auto c : words[i])temp[c]++;
        bool can=true;
        for(auto& x : temp)if(lcnt[x.first]<x.second)can=false;
        int one = INT_MIN;
        if(can){
            int s=0;
            for(auto&x : temp)lcnt[x.first]-=x.second,s+=score[x.first-'a']*x.second;
            one = solve(words,score,i+1,state)+s;
            for(auto& x:temp)lcnt[x.first]+=x.second;
        }
        int two=solve(words,score,i+1,state);
        return dp[i][state]=max(one,two);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(auto c : letters)lcnt[c]++;
        dp.resize(words.size(),vector<int>((1<<words.size()),-1));
        return solve(words,score,0,0);
    }
};