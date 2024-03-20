class Solution {
    const int MOD = 1e9+7;
public:
    int concatenatedBinary(int n) {
        vector<long long> ans(2);
        ans[0]=1;
        for(int i=1;i<n;i++){
            ans[i%2]=((ans[(i-1)%2]*((1LL<<((int)log2(i+1)+1))%MOD))%MOD+i+1)%MOD;
        }
        return ans[(n-1)%2];
    }
};
/*
1-> 1
2-> 1+10 -> 110 -> 6
3-> 1+10+11->11011->27
4-> 1+10+11+100->11011100->(27*2^(log2(4)+1)+4)%MOD=220
5-> 1+10+11+100+101->1765-> 220


*/