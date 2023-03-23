class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(const auto& v : roads){
            adj[v[0]-1].push_back({v[1]-1,v[2]});
            adj[v[1]-1].push_back({v[0]-1,v[2]});
        }
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int size=1,ans=INT_MAX;
        for(;!q.empty();size=q.size()){
            while(size--){
                int u = q.front();q.pop();
                for(const auto& [v,w] : adj[u]){
                    ans = min(ans,w);
                    if(vis[v])continue;
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};