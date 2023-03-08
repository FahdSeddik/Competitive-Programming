class Solution {
public:
    bool tamam(vector<int>& piles,int& mid,int& h){
        long long hrs=0;
        // cout<<mid<<"\n";
        for(const auto& c: piles){
            hrs += (c<=mid) ? 1:((c%mid==0) ? c/mid:c/mid+1);
        }
        return hrs<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=*min_element(piles.begin(),piles.end())/h,r=*max_element(piles.begin(),piles.end());
        cout<<"-------\n";
        while(l<r){
            int mid = l+(r-l)/2;
            if(mid && tamam(piles,mid,h))r=mid;
            else l=mid+1;
        }
        return max(l,1);
    }
};