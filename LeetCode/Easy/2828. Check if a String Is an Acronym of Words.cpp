class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ans="";
        for(auto st : words)ans+=st[0];
        return s==ans;
    }
};