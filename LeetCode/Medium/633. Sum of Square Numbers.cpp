class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long l=0,r=sqrt(c);l<=r;){
            long long prod=l*l+r*r;
            if(prod==c)return true;
            else if(prod<c)l++;
            else r--;
        }
        return false;
    }
};