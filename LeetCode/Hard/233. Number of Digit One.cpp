class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0) return 0;
        if (n <= 9) return 1;
        unordered_map<int, int> mp;
        mp[9] = 1;
        for (int i = 9; i < (INT_MAX - 9)/10; i = 10 * i + 9) mp[10 * i + 9] = mp[i] * 10 + i + 1;
        vector<int> digits;
        int temp = n;
        while(temp) {
            digits.push_back(temp % 10);
            temp = temp/10;
        }
        int k = digits.size();
        int j = 9;
        for (int i = 1; i < k - 1; i++) j = j * 10 + 9;
        int ans = 0;
        for (int i = k - 1; i >= 0; i--) {
            ans += digits[i] * mp[j];
            digits[i] > 1 ? ans += j + 1 : ans += 0;
            digits[i] == 1 ? (ans += n % (j + 1) + 1) : ans += 0; 
            j /= 10;
        }
        return ans;
    }
};