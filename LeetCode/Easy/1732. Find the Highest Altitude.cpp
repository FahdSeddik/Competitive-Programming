class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0,ans=0;
        for(auto i : gain)sum+=i,ans=max(ans,sum);
        return ans;
    }
};