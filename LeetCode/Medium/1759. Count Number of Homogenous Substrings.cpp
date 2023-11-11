class Solution {
public:
    int countHomogenous(string s) {
        int l = 0;
        long long res = 0;
        for(int r = 0; r<s.size(); r++){
            if(s[l]==s[r])res+=r-l+1;
            else res++,l=r;
        }
        return res%(1000000007);
    }
};