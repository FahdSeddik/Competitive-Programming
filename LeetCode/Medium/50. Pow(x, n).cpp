class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0)return 1;
        if(n<0){
            n=abs(n);
            x=1/x;
        }
        double xn=myPow(x,n/2);
        if(n%2==0) return xn*xn;
        else return x*xn*xn;
    }
};