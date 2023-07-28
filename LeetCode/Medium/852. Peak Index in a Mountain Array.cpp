class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //lol bs
        int l=0, r=arr.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])return mid;
            else if(arr[mid-1]>arr[mid])r=mid;
            else l=mid;
        }
        return l;
    }
};