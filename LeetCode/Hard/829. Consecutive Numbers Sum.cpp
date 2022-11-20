class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int coeff=2,add=1,ans=1;
        for(;n>add;add+=coeff,coeff++){
            if((n-add)%coeff==0)ans++;
        }
        return ans;
    }
};

/*
1x+0
2x+1
3x+3
4x+6
5x+10
6x+15
7x+16

*/