class Solution {
public:
    int strStr(string haystack, string needle) {
        //return haystack.find(needle);
        int n=haystack.size(),m=needle.size();
        if(!m)return 0;
        //kmp
        vector<int> lps = getlps(needle);
        for (int i = 0, j = 0; i < n;) {
            if (haystack[i] == needle[j]) i++,j++;
            if (j == m) return i-j;
            if (i < n && haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }
    vector<int> getlps(const string& needle){
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, j = 0; i < n;) {
            if (needle[i] == needle[j]) lps[i++] = ++j;
            else j? j=lps[j-1]:i++;
        }
        return lps;
    }
};