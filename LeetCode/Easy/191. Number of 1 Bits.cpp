class Solution {
public:
    int hammingWeight(uint32_t n,int ans=0) {
        //return __builtin_popcount(n);
        while(n)ans+= n&1,n>>=1;
        return ans;
    }
};