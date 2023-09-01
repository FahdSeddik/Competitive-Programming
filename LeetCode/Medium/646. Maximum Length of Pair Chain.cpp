class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[&](auto& a,auto& b){
            return a[1]<b[1];
        });
        int mx=INT_MIN;
        int ans=0;
        for(auto& v : pairs){
            if(v[0]>mx)mx=v[1],ans++;
        }
        return ans;
    }
};