class Solution {
    int n;
    long long fuel;
public:
    int dfs(vector<vector<int>>& adj,int src=0,int prev=-1){
        int children = 1;
        for(const auto& u : adj[src])if(prev!=u){
            children+=dfs(adj,u,src);
        }
        if(src)fuel+=(children+n-1)/n;
        return children;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        n = seats,fuel=0;
        vector<vector<int>> adj(roads.size()+1);
        for(const auto& e : roads){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(adj);
        return fuel;
    }
};