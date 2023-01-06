class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int m = *max_element(costs.begin(),costs.end())+1;
        int freq[m];
        memset(freq,0,sizeof(freq));
        for(const auto & c : costs)freq[c]++;
        int ans=0;
        for(int i=1;i<m && coins;i++){
            if(freq[i]){
                int n = min(coins/i,freq[i]);
                ans+=n;
                coins-=n*i;
            }
        }
        return ans;
    }
};