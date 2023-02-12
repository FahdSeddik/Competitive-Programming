class Solution {
public:
    int find(int x,vector<int>& parent){
        return x==parent[x] ? x: parent[x]=find(parent[x],parent);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size(),v_two=-1;
        vector<int> arr(n+1);
        for(const auto& e : edges){
            arr[e[1]]++;
            if(arr[e[1]]==2){
                v_two=e[1];
                break;
            }
        }
        if(v_two!=-1){
            for(int i=n-1;i>=0;i--){
                if(edges[i][1]==v_two){
                    vector<int> parent(n+1);
                    iota(parent.begin(),parent.end(),0);
                    vector<int> ans;
                    for(const auto& e : edges)if(e!=edges[i]){
                        const int u = find(e[0],parent);
                        const int v = find(e[1],parent);
                        if(u==v)ans = e;
                        else parent[u]=v;
                    }
                    if(!ans.size())return edges[i];
                }
            }
        }
        vector<int> parent(n+1);
        iota(parent.begin(),parent.end(),0);
        vector<int> ans;
        for(const auto& e : edges){
            const int u = find(e[0],parent);
            const int v = find(e[1],parent);
            if(u==v)ans = e;
            else parent[u]=v;
        }
        return ans;
    }
};