class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0,n=citations.size(),r=n-1;
        while(l<=r){
            int mid = (r-l)/2+l;
            if(citations[mid]<n-mid)l=mid+1;
            else r=mid-1;
        }
        return n-l;
    }
};