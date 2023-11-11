class Graph {
    vector<vector<pair<int,int>>> adj;
public:
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto& v : edges)adj[v[0]].emplace_back(v[1],v[2]);
    }
    
    void addEdge(vector<int> e) {
        adj[e[0]].emplace_back(e[1],e[2]);
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node1});
        vector<int> dist(adj.size(),INT_MAX);
        dist[node1]=0;
        while(!pq.empty()){
            int u = pq.top().second,cost=pq.top().first;
            pq.pop();
            if(cost>dist[u])continue;
            if(u==node2)return cost;
            for(auto& e : adj[u]){
                int v = e.first,w=e.second;
                if(dist[v] > w+dist[u]){
                    dist[v]=w+dist[u];
                    pq.push({dist[v],v});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */