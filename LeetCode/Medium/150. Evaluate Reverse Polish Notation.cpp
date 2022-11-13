class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/")st.push(stoi(tokens[i]));
            else{
                long long one = st.top();st.pop();
                long long two = st.top();st.pop();
                if(tokens[i]=="+"){
                    st.push(one+two);
                }else if(tokens[i]=="-"){
                    st.push(two-one);
                }else if(tokens[i]=="*"){
                    st.push(one*two);
                }else {
                    st.push(two/one);
                }
            }
        }
        return st.top();
    }
};