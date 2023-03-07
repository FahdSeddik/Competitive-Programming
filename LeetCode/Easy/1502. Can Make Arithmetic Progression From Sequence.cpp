class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int diff=arr[0]-arr[1];
        for(int i=0;i<n-1;i++)if(arr[i]-arr[i+1]!=diff)return false;
        return true;
    }
};