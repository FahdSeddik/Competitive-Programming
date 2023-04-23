class Solution {
public:
    int minInsertions(string s) {
        vector<int> memo(s.length(),0);
        int prev,temp;
        for(int i=s.length()-2;i>=0;i--){
            prev=0;
            for(int j=i;j<s.length();j++){
                temp=memo[j];
                memo[j]=s[i]==s[j] ? prev:1+min(memo[j],memo[j-1]);
                prev=temp;
            }
        }
        return memo[s.length()-1];
    }
};