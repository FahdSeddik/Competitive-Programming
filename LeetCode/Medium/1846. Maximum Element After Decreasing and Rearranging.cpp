class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]>1)arr[0]=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]>1)arr[i]=arr[i-1]+1;
        }
        return arr.back();
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();