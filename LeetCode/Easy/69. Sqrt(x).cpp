class Solution {
public:
    int mySqrt(long long x) {
        if(x==0||x==1)return x;
        long long l=0,r=x,mid;
        mid=(l+r)/2;
        while(l<r){
            long long prod = mid*mid;
            if(prod==x)return mid;
            if(prod<x)l=mid+1;
            else r=mid;
            mid=(l+r)/2;
        }
        return mid-1;
    }
};