class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int v : arr)mp[v]++;
        vector<pair<int,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[&](const auto&a,const auto&b){return a.second<b.second;});
        int rem=0;
        for(const auto&x : v)if(x.second<=k)rem++,k-=x.second;else break;
        return v.size()-rem;
    }
};