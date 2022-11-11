class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string> kn;
        for(int i=0;i<knowledge.size();i++){
            kn[knowledge[i][0]]=knowledge[i][1];
        }
        int i;
        for(i=0;i<s.size();i++){
            if(s[i]=='('){
                string key="";
                int j=i+1;
                while(s[j]!=')')key+=s[j],j++;
                if(key.size() && kn.count(key))ans+=kn[key];
                else ans+='?';
                i=j;
            }else ans+=s[i];
        }
        return ans;
    }
};