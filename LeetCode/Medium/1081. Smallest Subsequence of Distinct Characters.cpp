class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        vector<int> last(26),seen(26);
        for(int i=0;i<s.size();i++)last[s[i]-'a']=i;
        for(int i=0;i<s.size();i++){
            int cur = s[i]-'a';
            if(seen[cur])continue;
            while(!st.empty() && st.top()>s[i] && i<last[st.top()-'a'])seen[st.top()-'a']=0,st.pop();
            st.push(s[i]);
            seen[cur]=1;
        }
        string ans="";
        while(!st.empty())ans+=st.top(),st.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};