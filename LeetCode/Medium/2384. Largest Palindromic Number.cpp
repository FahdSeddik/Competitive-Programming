class Solution {
public:
    string largestPalindromic(string num) {
        int freq[10]={0};
        for(auto c : num)freq[c-'0']++;
        string lp, rp; 
        for (int i: num) {
            for (int j = 9; j >= 0; j--)  {
                if (freq[j] > 1 && (j > 0 || lp.size())) {
                    lp += '0' + j;
                    rp += '0' + j;
                    freq[j] -= 2;
                    break;
                }
            }
        }
        for (int i = 9; i >= 0; i--) {
            if (freq[i]) {
                lp += '0' + i;
                break;
            }
        }
        reverse(begin(rp), end(rp));
        return lp + rp;
    }
};