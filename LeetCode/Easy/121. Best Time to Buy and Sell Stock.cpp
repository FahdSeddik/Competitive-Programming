class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(mn>prices[i])mn=prices[i];
            else ans=max(ans,prices[i]-mn);
        }
        return ans;
    }
};