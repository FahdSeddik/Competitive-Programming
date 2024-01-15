class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    bool halvesAreAlike(string s) {
        int freq[26];memset(freq,0,sizeof(freq));
        for(int i=0,j=s.size()/2;i<s.size()/2;i++,j++){
            if(isVowel(s[i]))freq[s[i]>'Z' ? s[i]-'a':s[i]-'A']++;
            if(isVowel(s[j]))freq[s[j]>'Z' ? s[j]-'a':s[j]-'A']--;
        }
        int ans=0;
        for(int i=0;i<26;i++)ans+=freq[i];
        return !ans;
    }
};