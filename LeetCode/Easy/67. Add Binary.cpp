class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int diff = abs(i - j);
        if (i < j)a = string(diff, '0') + a;
        else if (j < i)b = string(diff, '0') + b;
        i = max(i, j);
        int carry = 0;
        string ans = "";
        while (i >= 0) {
            int sum = a[i] - '0' + b[i] - '0' + carry;
            if (sum >= 2)carry = 1;
            else carry = 0;
            ans += (char)(sum % 2 + '0');
            i--;
        }
        if (carry)ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};