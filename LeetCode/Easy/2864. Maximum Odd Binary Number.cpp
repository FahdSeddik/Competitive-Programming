class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0;
        for(char c : s)if(c=='1')ones++;
        for(int i=0;i<ones-1;i++)s[i]='1';
        for(int i=max(0,ones-1);i<s.size()-1;i++)s[i]='0';
        s[s.size()-1]='1';
        return s;
    }
};