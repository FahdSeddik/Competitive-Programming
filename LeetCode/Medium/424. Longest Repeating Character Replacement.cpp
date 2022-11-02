class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> alph(26);
        int res=0;
        int l=0,maxf=0;
        for(int i=0;i<s.size();i++){
            alph[s[i]-'A']++;
            maxf=max(maxf,alph[s[i]-'A']);
            while((i-l+1)-maxf>k)alph[s[l]-'A']--,l++;
            res=max(res,i-l+1);
        }
        return res;
    }
};