class Solution {
public:
    int arrangeCoins(int n) {
        if(n==1)return n;
        int l=1,r=n;
        while(l<r){
            int mid = (r-l)/2+l;
            long long s=1LL*mid*(mid+1)/2;
            if(s==n)return mid;
            else if(s>n)r=mid;
            else l=mid+1;
        }
        return l-1;
    }
};