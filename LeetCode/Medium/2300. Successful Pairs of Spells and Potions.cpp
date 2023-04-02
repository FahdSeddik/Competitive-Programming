class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
            ios_base::sync_with_stdio(0);
            cin.tie(0),cout.tie(0);
            sort(potions.begin(),potions.end());
            int n = spells.size();
            vector<int> ans(n);
            for(int i=0;i<n;i++){
                long long tofind = success/spells[i] + (success%spells[i]!=0);
                ans[i] = potions.end()-lower_bound(potions.begin(),potions.end(),tofind);
            }
            return ans;
    }
};