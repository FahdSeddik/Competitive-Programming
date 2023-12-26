class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++) if(s[i]-'0'==i%2)ans++;
        return min(ans,(int)s.length()-ans);
    }
};