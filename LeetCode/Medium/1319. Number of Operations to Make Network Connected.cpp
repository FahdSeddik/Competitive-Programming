class Solution {
    int parent[100001];
public:
    int find(int x){
        return parent[x]==x ? x:parent[x]=find(parent[x]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int disc=0,extra=0;
        iota(parent,parent+100001,0);
        for(const auto& v : connections){
            int a = find(v[0]);
            int b = find(v[1]);
            if(a==b)extra++;
            parent[b]=a;
        }
        for(int i=0;i<n;i++)find(i);
        unordered_set<int> s;
        for(int i=0;i<n;i++)s.insert(parent[i]);
        disc=s.size()-1;
        if(disc>extra)return -1;
        return disc;
    }
};