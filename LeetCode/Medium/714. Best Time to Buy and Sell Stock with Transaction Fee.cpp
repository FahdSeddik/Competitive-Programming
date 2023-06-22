class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int ans=0,buy=-prices[0];
        for(int i=1;i<n;i++){
            int t=buy;
            buy=max(buy,ans-prices[i]),ans=max(ans,t+prices[i]-fee);
        }
        return ans;
    }
};