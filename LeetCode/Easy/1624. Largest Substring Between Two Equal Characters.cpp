class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int first[26],last[26];
        memset(first,-1,sizeof(first)),memset(last,-1,sizeof(last));
        for(int i=0;i<s.size();i++){
            if(first[s[i]-'a']==-1)first[s[i]-'a']=i;
            else last[s[i]-'a']=i;
        }
        int ans=-1;
        for(int i=0;i<26;i++)if(first[i]!=-1 && last[i]!=-1)ans=max(ans,last[i]-first[i]-1);
        return ans;
    }
};