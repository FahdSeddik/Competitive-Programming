class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        int chars[256]={0};
        int n = s.size();
        for(int i=0;i<n;i++){
            if(mp.count(s[i])){
                if(mp[s[i]]!=t[i])return false;
            }else{
                if(chars[t[i]])return false;
                chars[t[i]]++;
                mp[s[i]]=t[i];
            } 
        }
        return true;
    }
};