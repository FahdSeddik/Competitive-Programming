class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(),candies.end()),n=candies.size();
        vector<bool> ans(n);
        for(int i=0;i<n;i++)ans[i]=candies[i]+extraCandies>=mx;
        return ans;
    }
};