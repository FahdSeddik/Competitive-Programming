class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[&](vector<int>& a,vector<int>& b){
            return a[0]==b[0] ? a[1]>b[1]:a[0]<b[0];
        });
        vector<int> lis;
        for(const auto& e : envelopes){
            int i = lower_bound(lis.begin(),lis.end(),e[1])-lis.begin();
            if(i>=lis.size())lis.push_back(e[1]);
            else lis[i]=e[1];
        }
        return lis.size();
    }
};