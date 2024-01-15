class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26],n=s.size();memset(freq,0,sizeof(freq));
        for(int i=0;i<n;i++)freq[s[i]-'a']++,freq[t[i]-'a']--;
        int ans=0;
        for(int i=0;i<26;i++)ans+=abs(freq[i]);
        return ans/2;
    }
};