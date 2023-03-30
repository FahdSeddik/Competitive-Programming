class Solution {
    
public:
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size(),ans=0,cursum=0;
        sort(sat.begin(),sat.end(),greater<int>());
        for(int i=0;i<n;i++){
            ans=max(ans,ans+cursum+sat[i]);
            cursum+=sat[i];
        }
        return ans;
    }
};