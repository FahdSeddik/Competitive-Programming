class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        vector<int> ans(t.size());
        for(int i=0;i<t.size();i++){
            if(st.empty() || t[st.top()]>=t[i]){
                st.push(i);
            }else if(t[st.top()]<t[i]){
                while(!st.empty() && t[st.top()]<t[i]){
                    ans[st.top()]=i-st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};