class Solution {
    int tot,n;
    vector<string> ans;
public:
    void dfs(unordered_map<string,vector<pair<string,int>>>& adj,string src){
        if(tot==n+1)return;
        for(auto& x : adj[src]){
            if(x.second==0)x.second=1,tot++,dfs(adj,x.first);
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<pair<string,int>>> adj;
        tot=0,n=tickets.size();
        for(auto& v : tickets)adj[v[0]].push_back({v[1],0});
        for(auto& x : adj)sort(x.second.begin(),x.second.end());
        dfs(adj,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};