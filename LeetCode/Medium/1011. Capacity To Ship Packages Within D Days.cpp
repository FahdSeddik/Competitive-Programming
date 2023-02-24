class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end()),
        r=accumulate(weights.begin(),weights.end(),0);
        while(l<r){
            int mid = (l+r)/2;
            int c=0,ships=1;
            for(const auto& w : weights){
                if(c+w>mid)c=0,ships++;
                c+=w;
            }
            if(ships<=days)r=mid;
            else l=mid+1;
        }
        return l;
    }
};