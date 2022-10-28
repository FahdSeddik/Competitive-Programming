class Solution {
    
public:
    bool isAnagram(string s, string t) {
        vector<int> alph1(26),alph2(26);
        for(int i=0;i<s.size();i++)alph1[s[i]-'a']++;
        for(int i=0;i<t.size();i++)alph2[t[i]-'a']++;
        
        return alph1==alph2;
    }
};