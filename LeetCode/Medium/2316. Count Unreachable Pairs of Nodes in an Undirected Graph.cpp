class Solution {
    int parent[100001];
public:
    int find(int x){
        return parent[x]==x ? x: parent[x]=find(parent[x]);
    }
    long long countPairs(long long n, vector<vector<int>>& edges) {
        long long ans=0;
        iota(parent,parent+n,0);
        for(const auto& v : edges){
            int a = find(v[0]);
            int b = find(v[1]);
            parent[b]=a;
        }
        unordered_map<int,long long> mp;
        for(int i=0;i<n;i++) mp[find(i)]++;
        for(const auto& x : mp){
            ans+= x.second*(n-x.second);
            n-=x.second;
        }
        return ans;
    }
};