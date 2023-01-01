class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,char> mpchar;
        stringstream ss(s);
        string str;
        vector<string> words;
        while(ss>>str)words.push_back(str);
        if(pattern.size()!=words.size())return false;
        for(int i=0;i<words.size();i++){
             if(mp.count(pattern[i]) && mp[pattern[i]]!=words[i])return false;
             if(mpchar.count(words[i]) && pattern[i]!=mpchar[words[i]])return false;
             mp[pattern[i]] = words[i];
             mpchar[words[i]] = pattern[i];
        }
        return true;
    }
};