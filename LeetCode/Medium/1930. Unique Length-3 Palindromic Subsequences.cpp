class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int first[26];
        int last[26];
        memset(first, -1, sizeof(first));
        memset(last, -1, sizeof(last));
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            else last[c] = i;
        }
        int count = 0;
        for (int c = 0; c < 26; c++) {
            if (first[c] != -1 && last[c] != -1) {
                bool found[26] = {false};
                int uniqueCount = 0;
                for (int j = first[c] + 1; j < last[c]; j++) {
                    int cj = s[j] - 'a';
                    if (!found[cj]) {
                        uniqueCount++;
                        found[cj] = true;
                    }
                    if (uniqueCount == 26) break;
                }
                count += uniqueCount;
            }
        }
        return count;
    }
};