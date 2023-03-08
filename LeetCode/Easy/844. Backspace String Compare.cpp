class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="",s2="";
        for(const auto& c : s){
            if(c!='#')s1+=c;
            else if(s1.size())s1.pop_back();
        }
        for(const auto& c : t){
            if(c!='#')s2+=c;
            else if(s2.size())s2.pop_back();
        }
        return s1==s2;
    }
};