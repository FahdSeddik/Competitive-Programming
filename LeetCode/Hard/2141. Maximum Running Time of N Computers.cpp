class Solution {
public:
    long long maxRunTime(long long n, vector<int>& batteries) {
        if(batteries.size()<n)return 0;
        long long l=1, r=accumulate(batteries.begin(),batteries.end(),0LL)/n;
        while(l<r){
            long long mid = (l+r+1)/2;
            long long tot=0;
            for(long long b : batteries){
                tot+=min(b,mid);
            }
            if(tot>=n*mid)l=mid;
            else r=mid-1;
        }
        return l;
    }
};