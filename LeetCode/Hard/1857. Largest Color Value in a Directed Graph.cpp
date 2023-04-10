class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> ind(n);
        for(const auto& v : edges){
            adj[v[0]].push_back(v[1]);
            ind[v[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!ind[i])q.push(i);
        }
        vector<vector<int>> dp(n,vector<int>(26));
        int ans=0,vis=0;
        while(!q.empty()){
            int u = q.front();q.pop();
            vis++;
            ans = max(ans, ++dp[u][colors[u]-'a']);
            for(auto v : adj[u]){
                for(int i=0;i<26;i++){
                    dp[v][i] = max(dp[v][i],dp[u][i]);
                }
                ind[v]--;
                if(!ind[v])q.push(v);
            }
        }
        return vis==n ? ans:-1;
    }
};

