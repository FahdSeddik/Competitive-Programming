class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> ans(n,-1);
        queue<pair<int,int>> q;
        q.push({0,-1});
        for(const auto& e : redEdges){
            adj[e[0]].push_back({e[1],0});
        }
        for(const auto& e : blueEdges){
            adj[e[0]].push_back({e[1],1});
        }
        for(int size=1,depth=0;!q.empty();depth++,size=q.size()){
            while(size--){
                const auto [node,pColor] = q.front();
                q.pop();
                ans[node] = ans[node]==-1? depth:ans[node];
                for(auto& [u, Color] : adj[node]){
                    if(u==-1 || Color==pColor)continue;
                    q.push({u,Color});
                    u=-1;
                }
            }
        }
        return ans;
    }
};