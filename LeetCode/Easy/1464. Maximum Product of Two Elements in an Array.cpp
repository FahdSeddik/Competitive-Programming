class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1=INT_MIN,mx2=INT_MIN;
        for(auto v : nums)if(v>mx1)mx2=mx1,mx1=v;
        else if(v>mx2)mx2=v;
        return (mx1-1)*(mx2-1);
    }
};