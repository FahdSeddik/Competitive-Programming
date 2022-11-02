class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size())return 0;
        unordered_set<char> st;
        int ans=1;
        st.insert(s[0]);
        for(int start=0,end=1;end<s.size() && start<=end;){
            while(start<end && st.count(s[end]))st.erase(s[start]),start++;
            st.insert(s[end]);
            ans=max(ans,(int)st.size());
            end++;
        }
        return ans;
    }
};