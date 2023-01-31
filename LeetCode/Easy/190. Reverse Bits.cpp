class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a=0,cnt;
        if(n==0)return 0;
        else cnt =__builtin_clz(n);
        while(n > 0)a <<= 1,a|= n&1,n>>=1;
        while(cnt--)a<<=1;
        return a;
    }
};