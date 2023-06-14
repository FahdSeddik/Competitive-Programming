#define ll long long
class Solution {
public:
    int maxValue(int n, int idx, int maxSum) {
        int start=1,end=maxSum;
        while(start<end){
            int mid=(start+end+1)>>1;
            int a=mid,d=-1;
            ll sum=-a;
            int terms=min(mid,idx+1);
            sum+=1ll*terms*(2*a+(terms-1)*d)/2;
            if(idx+1>terms) sum+=1ll*(idx+1-terms);
            terms=min(mid,n-idx);
            sum+=1ll*terms*(2*a+(terms-1)*d)/2;
            if(n-idx>terms) sum+=1ll*(n-idx-terms);
            if(sum<=1ll*maxSum) start=mid;
            else end=mid-1;
        }
        return start;
    }
};