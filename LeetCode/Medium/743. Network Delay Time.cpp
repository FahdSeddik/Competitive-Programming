class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(const auto&x : times) {
            adj[x[0]].push_back({x[2],x[1]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        int size=1;
        int ans=0,visited=0;
        vector<bool> vis(n+1);
        for(;!pq.empty();size=pq.size()){
            while(size--){
                auto x = pq.top();pq.pop();
                if(vis[x.second])continue;
                ans=max(ans,x.first);
                vis[x.second]=true,visited++;
                for(const auto& u : adj[x.second])if(!vis[u.second]){
                    pq.push({u.first+x.first,u.second});
                }
            }
        }
        return visited==n ?ans:-1;
    }
};