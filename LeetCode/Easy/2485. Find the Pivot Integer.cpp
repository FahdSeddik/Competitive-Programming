class Solution {
public:
    int pivotInteger(int n) {
        if(n==1)return 1;
        int l=1,r=n;
        int sum2 = n*(n+1)/2;
        while(l<r){
            int mid = (r-l)/2 + l;
            int sum = mid*(mid+1);
            if(sum2+mid==sum){
                return mid;
            }else if(sum2+mid>sum)l=mid+1;
            else r=mid-1;
        }
        return sum2+l==l*(l+1) ? l:-1;
    }
};