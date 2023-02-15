class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        unordered_set<char> st;
        vector<int> n_unique_left(n),n_unique_right(n);
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            n_unique_left[i]=st.size();
        }
        st.clear();
        for(int i=n-1;i>=0;i--){
            st.insert(s[i]);
            n_unique_right[i]=st.size();
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(n_unique_left[i]==n_unique_right[i+1])cnt++;
        }
        return cnt;
    }
};