class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> str;
        string st;
        while(ss>>st)str.push_back(st);
        string ans="";
        for(int i=str.size()-1;i>=1;i--){
            ans+=str[i];
            ans+=' ';
        }
        if(str.size())ans+=str[0];
        return ans;
    }
};