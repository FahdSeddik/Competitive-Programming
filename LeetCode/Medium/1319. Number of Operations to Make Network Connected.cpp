class Solution {
    int parent[100001];
public:
    int find(int x){
        return parent[x]==x ? x:parent[x]=find(parent[x]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        iota(parent,parent+n,0);
        for(const auto& v : connections){
            int a = find(v[0]);
            int b = find(v[1]);
            if(a==b)continue;
            else parent[b]=a,n--;
        }
        return n-1;
    }
};