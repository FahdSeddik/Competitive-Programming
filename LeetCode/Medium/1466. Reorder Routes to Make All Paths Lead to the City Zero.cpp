class Solution {
    int ans;
public:
    void dfs(vector<vector<pair<int,bool>>>& adj,int i=0,int prev=-1){
        for(const auto& conn : adj[i])if(conn.first!=prev){
            if(conn.second)ans++;
            dfs(adj,conn.first,i);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        ans=0;
        vector<vector<pair<int,bool>>> adj(n);
        for(const auto& v : connections){
            adj[v[0]].push_back({v[1],true});
            adj[v[1]].push_back({v[0],false});
        }
        dfs(adj);
        return ans;
    }
};