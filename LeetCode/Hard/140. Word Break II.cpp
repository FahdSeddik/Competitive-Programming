class Solution {
    vector<string> ans;
public:
    void cutdown(string s,unordered_set<string>& dict,string cur){
        if(s.empty()){
            ans.push_back(cur);
            return;
        }
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            if(dict.count(temp)){
                cout<<i<<" "<<s.substr(i+1)<<endl;
                cutdown(s.substr(i+1),dict,((cur=="") ? cur:cur+" ")+temp);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(const auto& s : wordDict)dict.insert(s);
        cutdown(s,dict,"");
        return ans;
    }
};