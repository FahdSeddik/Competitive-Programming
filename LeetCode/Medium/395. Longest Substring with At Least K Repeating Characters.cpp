class Solution {
public:
    int helper(string& s , int start , int end , int k) {
        if(start > end) return 0;
        if(start == end) return k==1;
        vector<int> freq(26 , 0);
        for(int i = start ; i <= end ; i++) freq[s[i]-'a']++;
        int res = 0, copy = start;
        for(int i = start ; i <= end ; i++) {
            if(freq[s[i]-'a'] < k) {
                int ans = helper(s,copy,i-1,k);
                res = max(res,ans);
                copy = i+1;
            }
        }
        if(copy != start) {
            int len = helper(s,copy,end,k);
            res = max(len,res);
        }
        else res = (end-start)+1;
        return res;
    }
    int longestSubstring(string s, int k) {
        int n = s.length();
        return helper(s,0,n-1,k);
    }
};