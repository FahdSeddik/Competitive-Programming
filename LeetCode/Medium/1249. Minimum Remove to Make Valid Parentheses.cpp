class Solution {
public:
    string minRemoveToMakeValid(string s) {
        for(int i=0,count=0;i<s.size();i++){
            if(s[i]=='(')count++;
            else if(s[i]==')'){
                if(count)count--;
                else s[i]='_';
            }
        }
        for(int i=s.size()-1,count=0;i>=0;i--){
            if(s[i]==')')count++;
            else if(s[i]=='('){
                if(count)count--;
                else s[i]='_';
            }
        }
        string ans="";
        for(const auto& c : s)if(c!='_')ans+=c;
        return ans;
    }
};