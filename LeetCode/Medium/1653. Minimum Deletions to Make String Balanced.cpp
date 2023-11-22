class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), cnt = 0, ans = 1e9;
        vector<int> cnta(n), cntb(n);

        for(int i=0; i<n; i++) {
            cntb[i] = cnt;
            if(s[i] == 'b') cnt++;
        }
        cnt = 0;
        for(int i=n-1; i>=0; i--) {
            cnta[i] = cnt;
            if(s[i] == 'a') cnt++;
        }

        for(int i=0; i<n; i++) ans = min(ans, cnta[i] + cntb[i]);
        return ans;
    }
};