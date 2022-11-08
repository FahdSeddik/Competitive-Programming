class Solution {
public:
    bool check(char c1,char c2){
        if(islower(c1) && isupper(c2) && c1==tolower(c2))return true;
        if(islower(c2) && isupper(c1) && c2==tolower(c1))return true;
        return false;
    }
    string makeGood(string s) {
        stack<char> st;
        st.push(s[0]);
        int i;
        for(i=1;i<s.size();){
            while(i<s.size() && !st.empty() && check(st.top(),s[i])){
                st.pop(),i++;
            }
            if(i<s.size())st.push(s[i]),i++;
        }
        string ans="";
        while(!st.empty())ans+=st.top(),st.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};