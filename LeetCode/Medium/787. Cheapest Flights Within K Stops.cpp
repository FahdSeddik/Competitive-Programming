class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //bfs with k
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dist(n,INT_MAX);
        for(const auto& e : flights)adj[e[0]].push_back({e[1],e[2]});
        queue<pair<int,int>> q;
        q.push({src,0});
        int size=1,depth=0;
        for(;!q.empty() && depth<=k;++depth,size=q.size()){
            while(size--){
                auto [u,cost] = q.front();q.pop();
                for(const auto& x : adj[u])if(x.second+cost<dist[x.first]){
                    dist[x.first]=x.second+cost;
                    q.push({x.first,dist[x.first]});
                }
            }
        }
        return dist[dst]==INT_MAX ? -1:dist[dst];
    }
};