class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1<n2){
            swap(s1, s2);
            swap(n1, n2);
        }
        vector<int> dp(n2+1, 0), prev(n2+1, 0);
        for (int x = n1-1; x >= 0; x--) {
            for (int y = n2-1; y >= 0; y--) {
                if (s1[x] == s2[y])
                    dp[y] = s1[x] + prev[y+1];
                else
                    dp[y] = max(prev[y], dp[y+1]);
            }
            prev=dp;
        }
        int AsciiSum = 0;
        for (char c : s1) AsciiSum += c;
        for (char c : s2) AsciiSum += c;
        return AsciiSum - 2*dp[0];
    }
};