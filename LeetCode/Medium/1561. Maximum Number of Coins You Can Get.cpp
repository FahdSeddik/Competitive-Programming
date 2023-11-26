class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int i=0,j=piles.size()-2;
        int ans=0;
        while(j-i>=1){
            ans+=piles[j];
            j-=2;
            i++;
        }
        return ans;
    }
};