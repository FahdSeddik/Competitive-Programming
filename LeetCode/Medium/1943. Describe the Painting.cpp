class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int,long long> mp;
        vector<vector<long long>> ans;
        for(const auto& v : segments)mp[v[0]]+=v[2],mp[v[1]]-=v[2];
        long long start=0,prev=0,cur=0;
        for(const auto& x : mp){
            prev=cur,cur+=x.second;
            if(prev>0)ans.push_back({start,x.first,prev});
            start=x.first;
        }
        return ans;
    }
};